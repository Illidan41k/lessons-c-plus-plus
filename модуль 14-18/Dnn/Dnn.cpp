#include "Dnn.h"
#include <QHeaderView>
#include <QDebug>
#include <QLineEdit>
#include <QHBoxLayout>

#include <iostream>
#include <algorithm>


Dnn::Dnn(QWidget* parent)
	: QWidget(parent)
{
	QHBoxLayout* hbox = new QHBoxLayout(this);
	QVBoxLayout* vbox = new QVBoxLayout(this);
	vbox->addSpacerItem(new QSpacerItem(10, 300));
	this->resize(1000, 1000);
	m_table = new QTableWidget(m_size, m_size, this);
	m_table->setMinimumSize(QSize(50 * m_size, 50 * m_size));
	m_table->setMaximumSize(QSize(50 * m_size, 50 * m_size));
	m_table->horizontalHeader()->setDefaultSectionSize(30);
	m_table->verticalHeader()->setDefaultSectionSize(30);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			m_table->setItem(i, j, new QTableWidgetItem);
		}
	}

	connect(m_table, &QTableWidget::cellClicked, this, &Dnn::draw);

	m_Label = new QLineEdit(this);
	m_predictions = new QListWidget(this);

	hbox->addWidget(m_table);
	hbox->addLayout(vbox);
	hbox->addWidget(m_Label);
	hbox->addWidget(m_predictions);

	auto dumpButton = new QPushButton("save digit", this);
	vbox->addWidget(dumpButton);
	auto trainButton = new QPushButton("train!", this);
	vbox->addWidget(trainButton);
	auto clearButton = new QPushButton("clear", this);
	vbox->addWidget(clearButton);

	auto forwardButton = new QPushButton("run it!", this);
	m_showButton = new QPushButton(QString::number(m_currentShowIndex), this);

	vbox->addWidget(forwardButton);
	vbox->addWidget(m_showButton);
	vbox->addSpacerItem(new QSpacerItem(10, 300));

	connect(dumpButton, &QPushButton::clicked, this, &Dnn::Dump);
	connect(trainButton, &QPushButton::clicked, this, &Dnn::TrainNet);
	connect(forwardButton, &QPushButton::clicked, this, &Dnn::Forward);
	connect(m_showButton, &QPushButton::clicked, this, &Dnn::Show);
	connect(clearButton, &QPushButton::clicked, this, &Dnn::Clear);

	m_cellsValues.resize(m_size * m_size);

	ReReadFileData();

	const int N = 5;
	int size[N] = { 100, 128, 256,128, 10 };
	string AF[N] = { "relu", "relu","relu","relu", "softmax" };
	m_net = NeuralNetwork(N, size, AF);
	m_net.New();

}

Dnn::~Dnn()
{}

void Dnn::draw(int x, int y)
{
	auto color = m_table->item(x, y)->backgroundColor();

	if (color == QColor(Qt::green))
	{
		color = QColor(Qt::white);
	}
	else
	{
		color = QColor(Qt::green);
	}

	m_table->item(x, y)->setBackground(color);

}

void Dnn::Dump()
{
	m_cellsValues.fill(false);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			auto color = m_table->item(i, j)->backgroundColor();

			if (color == QColor(Qt::green))
			{
				m_cellsValues[i * 10 + j] = true;

			}
		}
	}

	qDebug() << m_Label->text() << ": " << m_cellsValues;

	QString filename = "data.txt";

	QFile file(filename);
	if (file.open(QIODevice::Append)) {
		QTextStream stream(&file);
		stream << m_Label->text() << ", ";

		for (const auto cellValue : m_cellsValues)
		{
			stream << cellValue << ", ";
		}
		stream << endl;
	}

	ReReadFileData();
	Clear();
}

void Dnn::ReReadFileData()
{
	m_trainingData.clear();
	QFile learningDataFile("data.txt");

	learningDataFile.open(QIODevice::ReadOnly);

	QTextStream in(&learningDataFile);

	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList fields = line.split(",");
		QVector<bool> values;

		for (size_t i = 1; i <= m_size * m_size; i++)
		{
			values.push_back(fields[i].toInt());
		}

		m_trainingData.insert(fields[0].toInt(), values);
	}

	qDebug() << m_trainingData.keys();
}

void Dnn::TrainNet()
{
	auto len = m_trainingData.size();
	QVector<int> indexes = QVector<int>();
	indexes.resize(len);
	iota(indexes.begin(), indexes.end(), 0);

	std::random_shuffle(indexes.begin(), indexes.end());

	auto it = m_trainingData.begin();

	QVector<int> keys;
	QVector< QVector<bool>> digits;


	for (; it != m_trainingData.end(); ++it)
	{
		keys.push_back(it.key());
		digits.push_back(it.value());
	}


	for (int epochs = 0; epochs < 45; epochs++)
	{
		for (const auto index: indexes)
		{
			float oneHotData[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			oneHotData[keys[index]] = 1;

			float trainArray[100];

			for (size_t i = 0; i < digits[index].size(); i++)
			{
				trainArray[i] = digits[index][i];
			}
			m_net.ForwardFeed(trainArray);

			m_net.BackPropogation(oneHotData, 0.65);
		}
	}

}

void Dnn::Forward()
{
	float testData[100];

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			testData[i * 10 + j] = false;

			auto color = m_table->item(i, j)->backgroundColor();

			if (color == QColor(Qt::green))
			{
				testData[i * 10 + j] = true;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			std::cout << testData[i * 10 + j] << " ";
		}

		std::cout << std::endl;
	}

	m_net.ForwardFeed(testData);

	float output[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	m_net.GetPrediction(output);

	m_predictions->clear();

	for (uint8_t i = 0; i < 10; i++)
	{
		QString data = "prediction: " + QString::number(i) + "; confidence: " + QString::number(output[i] * 100);
		m_predictions->addItem(data);
	}
	
}

void Dnn::Show()
{
	auto len = m_trainingData.size();
	m_currentShowIndex = (m_currentShowIndex++) % (len-1);
	m_showButton->setText(QString::number(m_currentShowIndex));

	const auto& element = m_trainingData.cbegin() + m_currentShowIndex;

	m_Label->setText(QString::number(element.key()));

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			m_table->item(i, j)->setBackground(QColor(Qt::white));

			if (element.value()[i*10+j])
			{
				m_table->item(i, j)->setBackground(QColor(Qt::green));
			}
		}
	}
}

void Dnn::Clear()
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			m_table->setItem(i, j, new QTableWidgetItem);
		}
	}
}

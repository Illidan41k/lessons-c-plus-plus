#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMoveEvent>
#include <QTime>
#include <QComboBox>
#include <QDebug>
#include "Lesson17_Live.h"
#include <QSignalMapper>

Lesson17_Live::Lesson17_Live(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* hbox = new QVBoxLayout(this);
    hbox->setSpacing(2);

    //QPushButton* quitBtn = new QPushButton("Exit", this);

    //m_quitButton = new QPushButton("Exit", this);
   // hbox->addWidget(m_quitButton, 5, Qt::AlignLeft);

    //connect(m_quitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    //m_label = new QLabel("hi", this);
    //hbox->addWidget(m_label, 0, Qt::AlignCenter);
    //startTimer(1000);

    
    QPalette dark;
    dark.setColor(QPalette::Window, QColor(30, 30, 30));
    dark.setColor(QPalette::WindowText, Qt::white);

    QPalette light;
    light.setColor(QPalette::Window, QColor(220, 170, 220));
    light.setColor(QPalette::WindowText, Qt::black);

    m_appearences["Purple"] = light;
    m_appearences["Dark"] = dark;
    QStringList appearences = { "Purple", "Dark"};

    combo = new QComboBox();
    combo->addItems(appearences);
    hbox->addWidget(combo);

    auto appearenceChanger = [this](const QString& value) {
        qDebug() << value;
        qApp->setPalette(m_appearences[value]);
    };

    connect(combo, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated),
        this, appearenceChanger);
        
    std::function<void(const QString&)> stdFunctionObject = [this](const QString& value)
    {
        qDebug() << "application theme changed! " << value << " now";
    };

    connect(combo, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated),
       this, stdFunctionObject);

    
   /* QPushButton* button1 = new QPushButton("1", this);
    hbox->addWidget(button1, 3, Qt::AlignLeft);
    QPushButton* button2 = new QPushButton("2", this);
    hbox->addWidget(button2, 3, Qt::AlignLeft);
    QPushButton* button3 = new QPushButton("3", this);
    hbox->addWidget(button3, 3, Qt::AlignLeft);

    auto signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(button1, QString("first"));
    signalMapper->setMapping(button2, QString("second"));
    signalMapper->setMapping(button3, QString("third"));

    auto echoButton = [this](const QString& value) {
        qDebug() << value;
    };

    connect(button1, &QPushButton::clicked,
        signalMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
    connect(button2, &QPushButton::clicked,
        signalMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
    connect(button3, &QPushButton::clicked,
        signalMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));

    connect(signalMapper, static_cast<void(QSignalMapper::*)(const QString&)>(&QSignalMapper::mapped), echoButton);*/
    
}

Lesson17_Live::~Lesson17_Live()
{}

void Lesson17_Live::SetQuitActivation()
{
    m_quitActive = !m_quitActive;
    m_quitButton->setText(m_quitActive ? "Quit (active)" : "Quit (inactive)");

    if (m_quitActive)
    {
        m_quitConnection = connect(m_quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    }
    else
    {
        disconnect(m_quitConnection);
    }
}

void Lesson17_Live::keyPressEvent(QKeyEvent* event) {

    if (event->key() == Qt::Key_Escape) {
        qApp->quit();
    }
}

void Lesson17_Live::moveEvent(QMoveEvent* e) {

    int x = e->pos().x();
    int y = e->pos().y();

    QString text = QString::number(x) + "," + QString::number(y);

    setWindowTitle(text);
}

void Lesson17_Live::timerEvent(QTimerEvent* e)
{
    Q_UNUSED(e);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    m_label->setText(stime);
}


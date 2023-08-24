#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Dnn.h"
#include <QTableWidget>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QListWidget>
#include "NeuralNetwork.h"

class Dnn : public QWidget
{
    Q_OBJECT

public:
    Dnn(QWidget *parent = nullptr);
    ~Dnn();

private:
    void draw(int x, int y);
    void Dump();
    void ReReadFileData();
    void TrainNet();
    void Forward();
    void Show();
    void Clear();

    QTableWidget* m_table;
    QListWidget* m_predictions;
    QLineEdit* m_Label;

    QVector<bool> m_cellsValues;
    QMultiMap<int, QVector<bool>> m_trainingData;

    const int m_size = 10;
    uint16_t m_neurons[3] = { uint16_t(m_size*m_size), 256, 10 };
    NeuralNetwork m_net;
    size_t m_currentShowIndex{ 0 };
    QPushButton* m_showButton;
};

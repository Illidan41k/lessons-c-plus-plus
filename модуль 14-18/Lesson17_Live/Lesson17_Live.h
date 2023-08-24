#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lesson17_Live.h"
#include <QPushButton>
#include <QMetaObject>
#include <QLabel>
#include <QMap>

class Lesson17_Live : public QWidget
{
    Q_OBJECT

public:
    Lesson17_Live(QWidget *parent = nullptr);
    ~Lesson17_Live();



protected:
    void keyPressEvent(QKeyEvent* e);
    void moveEvent(QMoveEvent* e);

    void timerEvent(QTimerEvent* e);

private:
    void SetQuitActivation();
    bool m_quitActive = true;

    QPushButton* m_quitButton;
    QMetaObject::Connection m_quitConnection;

    QLabel* m_label;

    QComboBox* combo;

    QMap<QString, QPalette> m_appearences{};
};

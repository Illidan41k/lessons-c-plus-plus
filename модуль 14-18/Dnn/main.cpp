#include "Dnn.h"
#include <QtWidgets/QApplication>
#include "neuro.h"

int main(int argc, char *argv[])
{
//    uint16_t neurons[3] = { 16, 32, 10 }; //� ������ ������� ���������� ���������� �������� � ������ ����, ���-�� �������� �� ������ ���� ����� � �������
///* ������ ������ ������� ���� ������������ �������� ������ "�������" �� �������
//������ ������ ���������� ���� ���������� ���� �� ���������� ����
//*/
//    NeuralNet net(3, neurons);
//    double teach[4 * 4] = {
//        1,0,1,0,
//        1,1,1,0,
//        0,0,1,0,
//        0,0,1,0,
//    };
//    double test[4 * 4] = {
//        1,0,0,1,
//        1,1,1,1,
//        0,0,0,1,
//        0,0,0,1,
//    };
//    double ans[10] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, };
//    double output[10] = { 0 };
//    net.Forward(4 * 4, teach); 
//    net.getResult(10, output);
//    for (uint8_t i = 0; i < 10; i++) printf("%d: %f \n", i, output[i] * 100); 
//    net.learnBackpropagation(teach, ans, 0.50, 2); //������� ���� �� ������� "test", �������� ��������: 0.5
//
//    double teach1[16] = {
//        0,1,1,0,
//        1,0,1,0,
//        0,1,0,0,
//        0,1,1,1,
//    };
//
//    double ans1[10] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, };
//    net.learnBackpropagation(teach1, ans1, 0.50, 2);
//
//    printf("\n");
//    net.Forward(4 * 4, test);// ��������� ������ ���� ����� ��������
//    net.getResult(10, output);
//    for (uint8_t i = 0; i < 10; i++) printf("%d: %f \n", i, output[i] * 100);
//
//    net.Forward(4 * 4, teach);// ��������� ������ ���� ����� ��������
//    net.getResult(10, output);
//    for (uint8_t i = 0; i < 10; i++) printf("%d: %f \n", i, output[i] * 100);
//
//    net.Forward(4 * 4, teach1);// ��������� ������ ���� ����� ��������
//    net.getResult(10, output);
//    for (uint8_t i = 0; i < 10; i++) printf("%d: %f \n", i, output[i] * 100);
//
//    return 0;
    QApplication a(argc, argv);
    Dnn w;
    w.show();
    return a.exec();
}

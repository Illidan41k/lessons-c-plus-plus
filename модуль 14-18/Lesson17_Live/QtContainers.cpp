#include "QtContainers.h"
#include <qvector.h>
#include <qlist.h>
#include <qbytearray.h>
#include <qbitarray.h>
#include <qdebug.h>
#include <qcache.h>
#include <qset.h>
#include <iostream>


QtContainers::QtContainers()
{
	//vector();
	//byteArray();
	//bitArray();
	//list();

	//cache();
	//set();
}

void QtContainers::list()
{
	QList<int> list;

	list << 13 << 25 << 666;

	qDebug() << list;
}

void QtContainers::byteArray()
{
	//QByteArray a = "Sooooooooooooooommmmmmmmmmmmmmmmmmmmmmmmmmme tttttttttttttttttttteeeeeeeeeeeeeetttttttttttttttteeeeeeext...";
	QByteArray a = "qq";
	QByteArray aCompressed = qCompress(a, 9);

	qDebug() << aCompressed.size();
	qDebug() << a.size();

	qDebug() << qUncompress(aCompressed);
}

void QtContainers::vector()
{
	QVector<int> numbers{ 13,57,666,1024 };

	qDebug() << numbers;
}

void QtContainers::bitArray()
{
	QBitArray arr(3);
	arr[0] = arr[1] = true;
	arr[2] = false;

	qDebug() << arr;
}


void QtContainers::cache()
{
	QCache<int, QString> filesCache;
	filesCache.setMaxCost(5);

	filesCache.insert(1, new QString("qwerty.jpg"), 1);
	filesCache.insert(2, new QString("qwerty1.jpg"), 1);
	filesCache.insert(3, new QString("qwerty2.jpg"), 1);
	filesCache.insert(4, new QString("qwerty3.jpg"), 1);
	filesCache.insert(5, new QString("qwerty4.jpg"), 1);

	auto obj = filesCache.take(2);
	qDebug() << *obj;
	qDebug() << filesCache.keys();

	filesCache.insert(7, new QString("qwerty33.jpg"), 1);
	filesCache.insert(9, new QString("qwerty44.jpg"), 1);

	//obj = filesCache.take(2);
	//qDebug() << *obj;
	qDebug() << filesCache.keys();
}

void QtContainers::set()
{
	QSet<QString> set1;
	QSet<QString> set2;
	set1 << "Illidan" << "Tirend" << "Arthas";
	set2 << "Kenarius" << "Tirend" << "Malganus";

	//QSet<QString> setResult = set1.unite(set2);
	//qDebug() << setResult;

	//QSet<QString> setResult = set1.intersect(set2);
	//qDebug() << setResult;

	//QSet<QString> setResult = set1.subtract(set2);
	//qDebug() << setResult;
}

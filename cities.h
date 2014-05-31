#ifndef CITIES_H
#define CITIES_H

#include <QSet>
#include <QString>
#include <QVector>
#include <QChar>
#include <QtCore>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <string>

class Cities
{
public:
    Cities();
    QSet<QString> used_cities;
    QVector<QString> rus_cities;

    void read(QString Filename);
    QString new_city(QChar start_letter);
    bool is_Used(QString city);
    bool is_City(QString city);

};

#endif // CITIES_H

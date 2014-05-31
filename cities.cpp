#include "cities.h"

Cities::Cities()
{
    //QSet<QString> *used_cities = new QSet<QString>;
    //QSet<QString> *rus_cities = new QSet<QString>;
    read(":/MyFiles/city.txt");
    used_cities.insert("а");
}

void Cities::read(QString Filename)
{
    qDebug() << "Class cities constructor";
    QFile mFile(Filename);

    if(!mFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", mFile.errorString());
    }

    QTextStream in(&mFile);

    while(!in.atEnd()) {
        QString line = in.readLine();
        //qDebug() << line;
        rus_cities.push_back(line);
        //rus_cities.insert(line);
        //this->rus_cities->insert(line);
    }

    mFile.close();
}

QString Cities::new_city(QChar start_letter)
{
    QString tmp;
    qDebug() << "Вызвали new_city";
    int i = 0;
    while (i != rus_cities.size()) {
        if (rus_cities[i][0] == start_letter && !used_cities.contains(rus_cities[i]))
            break;
        else
            i++;
    }
    qDebug() << i;
    if (i != rus_cities.size()){
        used_cities.insert(rus_cities[i]);
        return rus_cities[i];
    }
    else
        return ("No city");
}

bool Cities::is_Used(QString city)
{
    if (!used_cities.contains(city)){
        used_cities.insert(city);
        return false;
    }
    else
        return true;

}

bool Cities::is_City(QString city)
{
    int i = rus_cities.indexOf(city);
    if (i == -1)
        return false;
    else
        return true;
}

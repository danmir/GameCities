#include <QtCore>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <string>
#include "mydialogwindow.h"
#include "gamewindow.h"
#include "cities.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWindow *start = new GameWindow;
    start->show();

    //MyDialogWindow *wnd = new MyDialogWindow;
    //wnd->show();

    return a.exec();
}

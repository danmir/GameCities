#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "mydialogwindow.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

private slots:
    void start_main_game();
};

#endif // GAMEWINDOW_H

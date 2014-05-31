#ifndef MYDIALOGWINDOW_H
#define MYDIALOGWINDOW_H

#include <QDialog>
#include <QLabel>
#include "cities.h"
#include "player.h"

namespace Ui {
class MyDialogWindow;
}

class MyDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialogWindow(QWidget *parent = 0);
    ~MyDialogWindow();

private:
    Ui::MyDialogWindow *ui;

private:
    Cities *ms;
    Player *player1;
    Player *player2;

public:
    void game_ended();

private slots:
    void OkEnabled();
    void on_game_end();
    void on_pushButton_clicked();
    void on_getCity_Button_clicked();
    void on_okButton_clicked();
};

#endif // MYDIALOGWINDOW_H

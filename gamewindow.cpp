#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(start_main_game()));

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start_main_game()
{
    MyDialogWindow *wnd = new MyDialogWindow;
    wnd->show();
    hide();
}

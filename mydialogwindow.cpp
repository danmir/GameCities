#include "mydialogwindow.h"
#include "cities.h"
#include "player.h"
#include "ui_mydialogwindow.h"

MyDialogWindow::MyDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialogWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 400);
    ui->okButton->setEnabled(false);

    QRegExp exp("[а-яА-я- ]{2,}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp, this));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(OkEnabled()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(on_game_end()));

    ms = new Cities;
    player1 = new Player; //user
    player2 = new Player; //cpu
}

void MyDialogWindow::OkEnabled()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

MyDialogWindow::~MyDialogWindow()
{
    delete ui;
}

void MyDialogWindow::on_pushButton_clicked()
{
    //static bool open = true;
    //ui->groupBox_2->setVisible(open);
    //open = !open;
    QMessageBox::information(this, "Игра города", "Введите российский город (до событий марта 2014) русскими буквами и нажмите ок");
}

void MyDialogWindow::on_getCity_Button_clicked()
{
    QString tmp = QString("М");
    QString was = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(was + "\n" + ms->new_city(tmp[0]));
}

void MyDialogWindow::on_okButton_clicked()
{
    QString input = ui->lineEdit->text();
    QString was = ui->plainTextEdit->toPlainText();
    qDebug() << was;
    if (!ms->is_City(input)) {
        QMessageBox::information(this, "Предупреждение", "Такого города в России нет");
    } else if (ms->is_Used(input)) {
        QMessageBox::information(this, "Предупреждение", "Такой город уже использовали");
    } else if (was != "" && was[was.size() - 1].toUpper() != input[0]) {
        QMessageBox::information(this, "Предупреждение", "Ваш город дожен начинаться с последней буквы предыдущего");
    } else {
        QString was = ui->plainTextEdit->toPlainText();
        QString letter = "ь";
        QString n_city;
        if (input[input.size() - 1] == letter[0])
            n_city = ms->new_city(input[input.size() - 2].toUpper());
        else
            n_city = ms->new_city(input[input.size() - 1].toUpper());
        if (n_city != "No city"){
            player2->score++;
            QString p2_s = QString::number(player2->score);
            ui->cpu_score->setText(p2_s);
        } else {
            player1->score++;
            game_ended();
        }
        ui->plainTextEdit->setPlainText(was + "\n" + input + "\n" + n_city);

        player1->score++;
        qDebug() << "P1 score: " << player1->score;
        QString p1_s = QString::number(player1->score);
        ui->player_score->setText(p1_s);

        QTextCursor c =  ui->plainTextEdit->textCursor();
        c.movePosition(QTextCursor::End);
        ui->plainTextEdit->setTextCursor(c);

        ui->lineEdit->setText("");

    }

}

void MyDialogWindow::game_ended(){
    int p1_score = player1->score;
    int p2_score = player2->score;
    QString p1_s = QString::number(player1->score);
    QString p2_s = QString::number(player2->score);
    QString final_text;
    if (p1_score > p2_score)
        final_text = "Вы победили со счетом: " + p1_s + ":" + p2_s;
    else if (p2_score > p1_score)
        final_text = "Вы  проиграли со счетом: " + p2_s + ":" + p1_s;
    else {
        QString p2_s = QString::number(player2->score + 1);
        final_text = "Вы сдались, а значит компьютер выиграл со счетом " + p2_s + ":" + p1_s;
    }
    QMessageBox::information(this, "Игра окончена", final_text);
    QCoreApplication::quit();
}

void MyDialogWindow::on_game_end(){
    game_ended();
}

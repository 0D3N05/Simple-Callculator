#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Logic.h"


using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Callculate_clicked()
{
    string input;

    input = ui->Input->text().toStdString();

    double result = evaluate(input);
    ui->Result->setText(QString::number(result));

}


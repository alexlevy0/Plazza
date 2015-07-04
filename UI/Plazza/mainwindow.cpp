#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int v = ui->spinBox->value();
    QString s = QString::number(v);

    if (ui->radioButton->isChecked() && v > 0)
        ui->textEdit->insertHtml("Regina S x" + s + "; ");
    if (ui->radioButton_2->isChecked() && v > 0)
        ui->textEdit->insertHtml("Regina M x" + s + "; ");
    if (ui->radioButton_3->isChecked() && v > 0)
        ui->textEdit->insertHtml("Regina L x" + s + "; ");
    if (ui->radioButton_4->isChecked() && v > 0)
        ui->textEdit->insertHtml("Regina XL x" + s + "; ");
    if (ui->radioButton_5->isChecked() && v > 0)
        ui->textEdit->insertHtml("Regina XXL x" + s + "; ");
}

void MainWindow::on_pushButton_2_clicked()
{
    int v = ui->spinBox_2->value();
    QString s = QString::number(v);

    if (ui->radioButton_6->isChecked() && v > 0)
        ui->textEdit->insertHtml("Margarita S x" + s + "; ");
    if (ui->radioButton_7->isChecked() && v > 0)
        ui->textEdit->insertHtml("Margarita M x" + s + "; ");
    if (ui->radioButton_8->isChecked() && v > 0)
        ui->textEdit->insertHtml("Margarita L x" + s + "; ");
    if (ui->radioButton_9->isChecked() && v > 0)
        ui->textEdit->insertHtml("Margarita XL x" + s + "; ");
    if (ui->radioButton_10->isChecked() && v > 0)
        ui->textEdit->insertHtml("Margarita XXL x" + s + "; ");
}

void MainWindow::on_pushButton_3_clicked()
{
    int v = ui->spinBox_3->value();
    QString s = QString::number(v);

    if (ui->radioButton_11->isChecked() && v > 0)
        ui->textEdit->insertHtml("Americaine S x" + s + "; ");
    if (ui->radioButton_12->isChecked() && v > 0)
        ui->textEdit->insertHtml("Americaine M x" + s + "; ");
    if (ui->radioButton_13->isChecked() && v > 0)
        ui->textEdit->insertHtml("Americaine L x" + s + "; ");
    if (ui->radioButton_14->isChecked() && v > 0)
        ui->textEdit->insertHtml("Americaine XL x" + s + "; ");
    if (ui->radioButton_15->isChecked() && v > 0)
        ui->textEdit->insertHtml("Americaine XXL x" + s + "; ");
}

void MainWindow::on_pushButton_4_clicked()
{
    int v = ui->spinBox_3->value();
    QString s = QString::number(v);

    if (ui->radioButton_16->isChecked() && v > 0)
        ui->textEdit->insertHtml("Fantasia S x" + s + "; ");
    if (ui->radioButton_17->isChecked() && v > 0)
        ui->textEdit->insertHtml("Fantasia M x" + s + "; ");
    if (ui->radioButton_18->isChecked() && v > 0)
        ui->textEdit->insertHtml("Fantasia L x" + s + "; ");
    if (ui->radioButton_19->isChecked() && v > 0)
        ui->textEdit->insertHtml("Fantasia XL x" + s + "; ");
    if (ui->radioButton_20->isChecked() && v > 0)
        ui->textEdit->insertHtml("Fantasia XXL x" + s + "; ");
}

void MainWindow::on_pushButton_5_clicked()
{
    QString cmd;
    std::string cmdString;
    cmd = ui->textEdit->toHtml();
    cmdString = cmd.toUtf8().constData();

    ui->textEdit->setText("Nos cuisinier s'activent au fourneau !");
}

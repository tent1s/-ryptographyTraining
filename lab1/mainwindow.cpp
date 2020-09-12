#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDataStream>
#include <iostream>
#include <QDebug>

QString full_fname;

const int m = 256;
const int a = 13;
const int b = 12;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Аффинный шифр"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_getFolderButton_clicked()
{
    full_fname = QFileDialog::getOpenFileName(this, tr("Open File"), "" , tr("*"));
    ui->folder->setText(full_fname);
}


void MainWindow::on_encryptButton_clicked()
{
    QFile file(full_fname);

    if ((file.exists())&&(file.open(QIODevice::ReadWrite)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str=str+file.readLine();
        }

        file.close();
        file.open(QIODevice::ReadWrite|QIODevice::Truncate);

        std::string text = str.toLocal8Bit().constData();
        for (size_t i = 0; i < text.length(); i++) {

            text[i] = (a * text[i] + b) % m;
        }
        QString qs = QString::fromLocal8Bit(text.c_str());
        file.write(qs.toUtf8());

        file.close();
    }
}



void MainWindow::on_decryptButton_clicked()
{
    QFile file(full_fname);
    if ((file.exists())&&(file.open(QIODevice::ReadWrite)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str=str+file.readLine();
        }

        file.close();
        file.open(QIODevice::ReadWrite|QIODevice::Truncate);

        std::string text = str.toLocal8Bit().constData();
        for (size_t i = 0; i < text.length(); i++) {
            text[i] = getReverse() * (text[i] - b) % m;
        }
        QString qs = QString::fromLocal8Bit(text.c_str());
        file.write(qs.toUtf8());

        file.close();
    }
}

int MainWindow::gcdex(int a, int b, int & x, int & y)
{
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcdex(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int MainWindow::getReverse()
{
    int x, y;
    int g = gcdex(a, m, x, y);
    if (g != 1){
        qDebug() << "no solution";
        return 0;
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}





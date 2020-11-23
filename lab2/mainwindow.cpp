#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDataStream>
#include <iostream>
#include <QDebug>

QString full_fname;
size_t mod;

const int key[]= {5,4,2,3,6,1};

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
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str=str+file.readLine();
        }

        file.close();
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);

        std::string text = str.toLocal8Bit().constData();
        mod=text.length() % 6;

        for (size_t i = 0; i < mod; i++)
            text += text[i];
        qDebug()<< mod;

        std::string result = "";
        for (size_t i = 0; i < text.length(); i += 6)
        {
            char position[6];
            for (int j = 0; j <6; j++)
                position[key[j] - 1] = text[i + j];

            for (int j = 0; j < 6; j++)
                result += position[j];
        }
        QString qs = QString::fromLocal8Bit(result.c_str());
        file.write(qs.toUtf8());

        file.close();
    }
}



void MainWindow::on_decryptButton_clicked()
{
    QFile file(full_fname);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str=str+file.readLine();
        }

        file.close();
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);

        std::string text = str.toLocal8Bit().constData();
        std::string result = "";

        for (size_t i = 0; i < text.length(); i += 6)
        {
            char position[6];
            for (int j = 0; j < 6; j++)
                position[j] = text[i + key[j] - 1];

            for (int j = 0; j < 6; j++)
                result += position[j];
        }

        long j=text.length();
        for (size_t i = 0; i < 6-mod; i++)
        {
            result[j-1] = NULL;
            j--;
        }
        qDebug()<< mod;
        QString qs = QString::fromLocal8Bit(result.c_str());
        file.write(qs.toUtf8());

        file.close();
    }
}








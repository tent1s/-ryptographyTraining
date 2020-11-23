#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dd.hpp"
#include <QFileDialog>
#include <QDataStream>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QBitArray>
#include <QTextCodec>
QString full_fname;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("S-блоки"));
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

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QByteArray block = file.readAll();
        QBitArray bits=by2bi(block);
        QString bit_line= incript(bi2str(by2bi(block)));
        int mod = (bit_line.size() / 6)*6;
        std::string str = bit_line.toLocal8Bit().constData();
        for (int i=0;i<mod;++i)
        {
           bits[i] = (int)str[i]-48;
        }

        file.close();
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);

        file.write(convertbybyte(bits));

        file.close();
    }
}



void MainWindow::on_decryptButton_clicked()
{
    QFile file(full_fname);

    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QByteArray block = file.readAll();
        QBitArray bits=by2bi(block);
        QString bit_line= decript(bi2str(by2bi(block)));

        int mod = (bit_line.size() / 6)*6;
        std::string str = bit_line.toLocal8Bit().constData();
        for (int i=0;i<mod;++i)
        {
           bits[i] = (int)str[i]-48;
        }

        file.close();
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);

        file.write(convertbybyte(bits));
        file.close();
    }
}










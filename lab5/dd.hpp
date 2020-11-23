#ifndef DD_H
#define DD_H
#include <QBitArray>
#include <QTextCodec>
#include <iostream>
#include <QDataStream>
#include <QDebug>
#include<math.h>
#include<conio.h>
const int a=1;
const int b=5;
const int sbox[4][16] = {{7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
                         {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
                         {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
                         {3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14}};
QBitArray by2bi(QByteArray data)
{
    QBitArray bits(data.count()*8);
    for (int i = 0; i < data.count(); ++i) {
        for (int b = 0; b < 8; b++) {
            bits.setBit( i * 8 + b , data.at(i) & (1<<  b) );
        }
    }
    return bits;
}
QByteArray convertbybyte(QBitArray bits)
{
    QByteArray bytes;
    for(int b=0; b<bits.count(); ++b){
        bytes[b/8] = (bytes.at(b/8) | ((bits[b]?1:0)<<(b%8)));
    }
    return bytes;
}
int dec2bin_notation(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}
int in2bin_notation(QString num){
    int n=num.count(), sum=0 , i;
    for (i=n-1;i>-1;i--)
       if (num[i]=='1')    sum+=pow(2,n-(i+1)) ;
    return sum;
}
QString incript(QString bits_line)
{
    QString row;
    QString column;
    int mod = (bits_line.size() / 6)*6;
    for(int j=0;j<mod; j+=6)
    {
        row="";
        column="";
        row+=bits_line[a-1+j];
        row+=bits_line[b-1+j];
        for(int i=0; i<6; ++i){
            if((i!=a-1)&(i!=b-1)){
                column+=bits_line[i+j];
            }
        }
        QString str = QString::number(dec2bin_notation(sbox[in2bin_notation(row)][in2bin_notation(column)]));

        while(str.size()<4){
            str="0"+str;
        }
        int count=0;
        for(int i=0; i<6; ++i){
            if((i!=a-1)&(i!=b-1)){
                bits_line[i+j]=str[count];
                count++;
            }
        }
    }
    return bits_line;
}
QString decript(QString bits_line)
{
    QString row;
    QString key;
    int column;
    int mod = (bits_line.size() / 6)*6;
    for(int j=0;j<mod; j+=6)
    {
        row="";
        key="";
        row+=bits_line[a-1+j];
        row+=bits_line[b-1+j];
        for(int i = 0; i < 6; i++){
            if((i!=a-1)&(i!=b-1)){
                key+=bits_line[i+j];
            }
        }
        for(int i=0; i<16; i++){
            if(in2bin_notation(key)==sbox[in2bin_notation(row)][i]){
                column= i;
            }
        }
        QString str = QString::number(dec2bin_notation(column));
        while(str.size()<4){
            str="0"+str;
        }
        int count=0;
        for(int i=0; i<6; ++i){
            if((i!=a-1)&(i!=b-1)){
                bits_line[i+j]=str[count];
                count++;
            }
        }
    }
    return bits_line;
}

QString bi2str(QBitArray bits)
{
    QString tempStr = "";
    for (int i = 0; i < bits.count(); i++) {
        tempStr+=bits.at(i)?'1':'0';
    }
    return tempStr;
 }

#endif // DD_H

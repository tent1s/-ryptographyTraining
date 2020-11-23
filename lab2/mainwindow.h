#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int gcdex(int a, int b, int & x, int & y);
    int getReverse();
private slots:
    void on_getFolderButton_clicked();
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

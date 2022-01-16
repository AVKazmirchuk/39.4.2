#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QLabel* l1;
    QLineEdit* le;
    QLabel* l2;
private slots:
    void regExp(const QString&);
    void setOkLabel();
    void setNotOkLabel();
};
#endif // MAINWINDOW_H

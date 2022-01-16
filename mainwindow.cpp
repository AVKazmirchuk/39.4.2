#include <QWidget>
#include <QVBoxLayout>
#include <QRegularExpression>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* w = new QWidget();

    QVBoxLayout* vbl = new QVBoxLayout;

    l1 = new QLabel("Example: +79012345678");
    le = new QLineEdit();
    l2 = new QLabel();

    vbl->addWidget(l1);
    vbl->addWidget(le);
    vbl->addWidget(l2);

    w->setLayout(vbl);

    setCentralWidget(w);

    connect(le, &QLineEdit::textEdited, this, &MainWindow::regExp);
}

MainWindow::~MainWindow()
{
}

void MainWindow::regExp(const QString &txt)
{
    QRegularExpression exp("^\\+[0-9]{11}\\z");
    if (exp.match(txt).hasMatch()) setOkLabel();
    else setNotOkLabel();
}

void MainWindow::setOkLabel()
{
    l2->setText("Ok!");
    l2->setStyleSheet("QLabel{color:green;}");
}

void MainWindow::setNotOkLabel()
{
    l2->setText("Not Ok!");
    l2->setStyleSheet("QLabel{color:red;}");
}


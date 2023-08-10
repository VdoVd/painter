#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<vector>
#include<QPoint>
#include<QPainter>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QVector<QPoint> &lastLine = lines.last();
    lastLine.append(event->pos());
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QVector<QPoint> newLine;
    newLine.append(event->pos());
    lines.append(newLine);
    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QVector<QPoint> &lastLine = lines.last();
    lastLine.append(event->pos());
    update();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter.setPen(pen);

    for(auto &line:lines)
    {
        painter.drawPolyline(line.data(),line.size());
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <iostream>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  QImage image("./GrayScale.png");
  pix = QPixmap::fromImage(image);
  scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);
  scene->addPixmap(pix);
  scene->setSceneRect(QRectF(QPoint(0,0),pix.size()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  ui->graphicsView->setMouseTracking(true);
  scene->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) 
{
  if (event->type() ==  QEvent::GraphicsSceneMouseMove ) {
    QGraphicsSceneMouseEvent *mouseEvent = dynamic_cast<QGraphicsSceneMouseEvent*>(event);

    QPointF img_coord_pt = mouseEvent->scenePos();
    
    double x = img_coord_pt.x();
    double y = img_coord_pt.y();
    
    QColor color = QColor(pix.toImage().pixel(x,y));
    int average = (color.red()+color.green()+color.blue())/3;

    ui->label_X->setText(QString::number(x));
    ui->label_Y->setText(QString::number(y));
    ui->label_Value->setText(QString::number(average));

    return true;
  } else {
    return QObject::eventFilter(obj, event);
  }
}


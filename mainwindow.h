#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
  class MainWindow;
}

class QMouseEvent;

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  private slots:
  void on_pushButton_clicked();

 protected:
  bool eventFilter(QObject *obj, QEvent *event);
  
 private:
  Ui::MainWindow *ui;
  QGraphicsScene* scene;
  QGraphicsItem* item;
  QPixmap pix;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QtCharts/QtCharts>
#include <QtCore>
#include <QtGui>

#include "configuration.h"
#include "plotconfig.h"
#include "schema_display.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  // Configuration
  Configuration config;

  Configuration *getConfig();

 private slots:

  void on_actionSchema_triggered();

  void on_calcButton_clicked();

  void on_clrButton_clicked();

  void on_tbButton_clicked();

  void on_horizontalScrollBar_sliderMoved(int position);

  void on_actionPlot_option_triggered();

 private:
  Ui::MainWindow *ui;
  Schema_display *schema_wid;
  PlotConfig *plotconfig_wid;
  QGraphicsScene *scena;
  qint64 xcalcMax = 100;
};
#endif  // MAINWINDOW_H

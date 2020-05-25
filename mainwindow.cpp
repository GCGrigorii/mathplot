#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  //  this->ui->graphicsView->setScene(scena);
}

MainWindow::~MainWindow() { delete ui; }

Configuration* MainWindow::getConfig() { return &config; }

void MainWindow::on_actionSchema_triggered() {
  schema_wid = new Schema_display(this);
  schema_wid->show();
}

void MainWindow::on_actionPlot_option_triggered() {
  plotconfig_wid = new PlotConfig(this, &config);
  plotconfig_wid->show();
}

void MainWindow::on_calcButton_clicked() {
  // Get value
  try {
    double E(0), R(0), L(0), C(0), e(0), h(0), hi(0);
    E = this->ui->lineEdit->text().toDouble();
    R = this->ui->lineEdit_2->text().toDouble();
    C = this->ui->lineEdit_3->text().toDouble();
    L = this->ui->lineEdit_4->text().toDouble();
    e = this->ui->lineEdit_5->text().toDouble();
    h = this->ui->lineEdit_6->text().toDouble();
    hi = this->ui->lineEdit_7->text().toDouble();

    // Try to calc
    double x1(0), x1t(0), y1(0), y1t(0);

    // Draw to plot
    QVector<double> x(15), y(15);
    for (int i(0), j(0); i < 1000; i += 10, j += 2) {
      x.append(i);
      y.append(j);
    }
    xcalcMax = 1000;
    ui->widgetPlot->addGraph();
    ui->widgetPlot->graph(0)->setData(x, y);
    ui->widgetPlot->xAxis->setLabel("x");
    ui->widgetPlot->yAxis->setLabel("y");
    ui->widgetPlot->xAxis->setRange(config.xmin, config.xmax);
    ui->widgetPlot->yAxis->setRange(config.ymin, config.ymax);
    ui->widgetPlot->graph(0)->setPen(config.fpen);
    ui->widgetPlot->replot();

  } catch (QException ex) {
    QDebug(new QString("Exeption"));
    QDebug(new QString(ex.what()));
  } catch (...) {
    QDebug(new QString("Another exeption"));
  }
}

void MainWindow::on_clrButton_clicked() {
  ui->widgetPlot->clearGraphs();
  ui->widgetPlot->xAxis->setRange(config.xmin, config.xmax);
  ui->widgetPlot->yAxis->setRange(config.ymin, config.ymax);
  ui->widgetPlot->replot();
}

void MainWindow::on_tbButton_clicked() {}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position) {
  if (xcalcMax > config.xmax) {
    int xm, xz;
    xm = ((xcalcMax / 100) * position) - config.xmax;
    xz = ((xcalcMax / 100) * position) + config.xmax;
    if (xm > 0 && xz > config.xmax)
      ui->widgetPlot->xAxis->setRange(xm, xz);
    else
      ui->widgetPlot->xAxis->setRange(config.xmin, config.xmax);
  }
  ui->calcTimeLCD->display(position);
  ui->widgetPlot->replot();
}

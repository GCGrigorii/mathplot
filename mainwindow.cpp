/***************************************************************************
**                                                                        **
**  MathPlot - my university lab                                          **
**  Copyright © 2020 Tonkonog Grigoriy                                    **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Тонконог Григорий                                    **
**            Email: grigoriit@protonmail.com, giit@pm.me                 **
**             Date: 27.05.20                                             **
**          Version: 0.1.2                                                **
****************************************************************************/

#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  //  this->ui->graphicsView->setScene(scena);
  ui->tableWidget->hide();
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
    QVector<double> k;  // For Runge-Kutta^4
    QVector<double> y1, y2;
    y1.append(0);
    y2.append(E / (R * C));
    // Calc logic
    // Find 4 first value
    k.clear();
    for (int i(0); i < 200; i++) {
      double y = E / (L * C) - (R / L) * y2[i] - (1 / (L * C)) * y1[i];
      k.append(y);
      k.append(y + (h * k[0]) / 2);
      k.append(y + (h * k[1]) / 2);
      k.append(y + (h * k[2]));
      y2.append(y + (h * (k[0] + (2 * k[1]) + (2 * k[2]) + k[3])) / 6);
      y1.append(y);
    }
    // Next calc

    // Add to tableView
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(y1.length());
    ui->tableWidget->showGrid();

    // Draw to plot
    xcalcMax = 1000;
    ui->widgetPlot->addGraph();
    ui->widgetPlot->addGraph();
    for (int i = 0; i < y1.length(); i++) {
      ui->widgetPlot->graph(0)->addData(y1[i], i);
      ui->widgetPlot->graph(1)->addData(y2[i], i);
      ui->tableWidget->setItem(
          i, 0, new QTableWidgetItem(QString::number(y1[i], 'f', 4)));
      ui->tableWidget->setItem(
          i, 1, new QTableWidgetItem(QString::number(y2[i], 'f', 4)));
    }
    ui->widgetPlot->xAxis->setLabel("x");
    ui->widgetPlot->yAxis->setLabel("y");
    ui->widgetPlot->xAxis->setRange(config.xmin, config.xmax);
    ui->widgetPlot->yAxis->setRange(config.ymin, config.ymax);
    ui->widgetPlot->graph(0)->setPen(config.fpen);
    ui->widgetPlot->graph(1)->setPen(config.spen);
    ui->widgetPlot->replot();

  } catch (QException ex) {
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
  ui->tableWidget->clear();
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

void MainWindow::on_tbwButton_clicked() {
  if (ui->tableWidget->isHidden())
    ui->tableWidget->show();
  else
    ui->tableWidget->hide();
}

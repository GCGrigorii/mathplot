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

#include <iostream>

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
  Schema_display* schema_wid;
  schema_wid = new Schema_display(this);
  schema_wid->show();
}

void MainWindow::on_actionPlot_option_triggered() {
  PlotConfig* plotconfig_wid;
  plotconfig_wid = new PlotConfig(this, &config);
  plotconfig_wid->show();
}

void MainWindow::on_actionAbout_triggered() {
  About* about_wid;
  about_wid = new About(this);
  about_wid->show();
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
    QVector<double> y1, y2;
    y1.append(0);
    y2.append(E / (R * C));
    // Calc logic
    // Getting 4 start value

    for (int i(0); i < 4; i++) {
      y1.append(y2[i]);
      double y2x = (E / (L * C) - (R / L) * y2[i] - (1 / (L * C)) * y1[i]);
      double k2 = (y2x + (h / 2) * y2x);
      double k3 = (y2x + (h / 2) * k2);
      double k4 = (y2x + h * k3);
      y2.append(y1[i + 1] + (h / 6) * (y2x + 2 * k2 + 2 * k3 + k4));
    }

    for (int i(3); (i * h) < hi; i++) {
      std::vector<double> yx, y1kx;
      yx.push_back(E / (L * C) - (R / L) * y2[i] - y1[i] / (L * C));
      yx.push_back(E / (L * C) - (R / L) * y2[i - 1] - y1[i - 1] / (L * C));
      yx.push_back(E / (L * C) - (R / L) * y2[i - 2] - y1[i - 2] / (L * C));
      yx.push_back(E / (L * C) - (R / L) * y2[i - 3] - y1[i - 3] / (L * C));
      double y1x = y1[i] + (h / 24) * ((55 * yx[0]) - (59 * yx[1]) +
                                       (37 * yx[2]) - (9 * yx[3]));
      y1kx.push_back(
          y1[i] + (h / 24) * ((9 * (y1x + 19 * yx[0])) - (5 * yx[1]) + yx[2]));
      for (int j(1); (y1kx[j] - y1kx[j - 1]) < e; j++)
        y1kx.push_back(y1[i] + (h / 24) * ((9 * (y1kx[j - 1] + 19 * yx[0])) -
                                           (5 * yx[1]) + yx[2]));
      y2.append(y1kx[y1kx.size() - 1]);
      y1.append(y2[i]);
    }

    // Next calc

    // Add to tableView
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(y1.length());
    ui->tableWidget->showGrid();

    // AutoResize
    if (AutoSized) {
      double max;
      for (int i(0); i < y2.size(); i++)
        if (max < y2[i]) max = y2[i];
      ui->widgetPlot->xAxis->setRange(config.xmin, y2.size());
      ui->widgetPlot->yAxis->setRange(config.ymin, max);
    }

    // Draw to plot
    xcalcMax = 1000;
    ui->widgetPlot->addGraph();
    ui->widgetPlot->addGraph();
    for (int i = 0; i < y1.length(); i++) {
      ui->widgetPlot->graph(0)->addData(i, y1[i]);
      ui->widgetPlot->graph(1)->addData(i, y2[i]);
      ui->tableWidget->setItem(
          i, 0, new QTableWidgetItem(QString::number(y1[i], 'f', 4)));
      ui->tableWidget->setItem(
          i, 1, new QTableWidgetItem(QString::number(y2[i], 'f', 4)));
    }
    ui->widgetPlot->xAxis->setLabel("x");
    ui->widgetPlot->yAxis->setLabel("y");
    if (!AutoSized) {
      ui->widgetPlot->xAxis->setRange(config.xmin, config.xmax);
      ui->widgetPlot->yAxis->setRange(config.ymin, config.ymax);
    }
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

void MainWindow::on_checkBox_stateChanged(int isCheked) {
  AutoSized = isCheked;
}

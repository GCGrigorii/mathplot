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

  void on_tbwButton_clicked();

 private:
  Ui::MainWindow *ui;
  Schema_display *schema_wid;
  PlotConfig *plotconfig_wid;
  QGraphicsScene *scena;
  qint64 xcalcMax = 100;
};
#endif  // MAINWINDOW_H

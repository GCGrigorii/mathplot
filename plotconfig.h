/***************************************************************************
**                                                                        **
**  MathPlot                                                              **
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

#ifndef PLOTCONFIG_H
#define PLOTCONFIG_H

#include <QString>
#include <QWidget>

#include "configuration.h"

namespace Ui {
class PlotConfig;
}

class PlotConfig : public QWidget {
  Q_OBJECT

 public:
  explicit PlotConfig(QWidget *parent = nullptr, Configuration *cf = nullptr);
  explicit PlotConfig(QWidget *parent = nullptr);
  ~PlotConfig();

  Configuration *conf;

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

 private:
  Ui::PlotConfig *ui;
};

#endif  // PLOTCONFIG_H

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

#include "plotconfig.h"

#include "ui_plotconfig.h"

PlotConfig::PlotConfig(QWidget* parent, Configuration* cf)
    : QWidget(parent), conf(cf), ui(new Ui::PlotConfig) {
  ui->setupUi(this);
  ui->lineEdit_xmax->setText(QString::number(cf->xmax));
  ui->lineEdit_xmin->setText(QString::number(cf->xmin));
  ui->lineEdit_ymax->setText(QString::number(cf->ymax));
  ui->lineEdit_ymin->setText(QString::number(cf->ymin));
  int r, g, b;
  cf->fpen.color().getRgb(&r, &g, &b);
  ui->lineEdit->setText(QString::number(r));
  ui->lineEdit_2->setText(QString::number(g));
  ui->lineEdit_3->setText(QString::number(b));
  cf->spen.color().getRgb(&r, &g, &b);
  ui->lineEdit_4->setText(QString::number(r));
  ui->lineEdit_5->setText(QString::number(g));
  ui->lineEdit_6->setText(QString::number(b));
}
PlotConfig::PlotConfig(QWidget* parent)
    : QWidget(parent), ui(new Ui::PlotConfig) {
  ui->setupUi(this);
}

PlotConfig::~PlotConfig() { delete ui; }

void PlotConfig::on_pushButton_clicked() {
  // save
  conf->xmax = ui->lineEdit_xmax->text().toInt();
  conf->xmin = ui->lineEdit_xmin->text().toInt();
  conf->ymax = ui->lineEdit_ymax->text().toInt();
  conf->ymin = ui->lineEdit_ymin->text().toInt();
  conf->fpen.setColor(QColor(ui->lineEdit->text().toInt(),
                             ui->lineEdit_2->text().toInt(),
                             ui->lineEdit_3->text().toInt()));
  conf->spen.setColor(QColor(ui->lineEdit_4->text().toInt(),
                             ui->lineEdit_5->text().toInt(),
                             ui->lineEdit_6->text().toInt()));
  this->close();
}

void PlotConfig::on_pushButton_2_clicked() {
  // Cancel
  this->close();
}

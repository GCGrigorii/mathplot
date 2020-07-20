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

#include "schema_display.h"

#include "ui_schema_display.h"

Schema_display::Schema_display(QWidget *parent)
    : QDialog(parent), ui(new Ui::Schema_display) {
  ui->setupUi(this);
}

Schema_display::~Schema_display() { delete ui; }

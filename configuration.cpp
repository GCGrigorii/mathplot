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

#include "configuration.h"

Configuration::Configuration() {
  xmin = 0;
  xmax = 100;
  ymin = 0;
  ymax = 3;
  fpen.setColor(QColor(0, 0, 255));
  spen.setColor(QColor(0, 255, 0));
  tpen.setColor(QColor(255, 0, 0));
}
Configuration::~Configuration() {}

void Configuration::loadConfig(std::string filename) {
  //  if (!filename.empty()) {
  //    QFile file;
  //    file.open(*(filename.c_str()), QIODevice::ReadWrite);
  //    parseFile(&file);
  //  } else
  //    throw("File open exeption");
}

// void Configuration::saveConfig(std::string filename) {}

// void Configuration::loadConfig() {}

// void Configuration::saveConfig() {}

// void Configuration::setConfigFile(std::string filename) {}

// bool parseFile(QFile *file) {}

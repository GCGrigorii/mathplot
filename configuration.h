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

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QException>
#include <QFile>
#include <QPen>
#include <QtGlobal>
#include <string>

class Configuration {  // TODO: work with that
 public:
  Configuration();
  ~Configuration();

  void loadConfig(const std::string filename);
  void saveConfig(const std::string filename);
  void loadConfig();
  void saveConfig();
  void setConfigFile(const std::string filename);

  qint64 xmin, xmax, ymin, ymax;
  QPen fpen, spen, tpen;
  std::string fileName;

 private:
  bool parseFile(QFile *file);
};

#endif  // CONFIGURATION_H

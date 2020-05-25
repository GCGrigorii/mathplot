#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QPen>
#include <QtGlobal>

class Configuration {
 public:
  Configuration();
  ~Configuration();

  qint64 xmin, xmax, ymin, ymax;
  QPen fpen, spen, tpen;
};

#endif  // CONFIGURATION_H

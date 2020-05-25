#include "configuration.h"

Configuration::Configuration() {
  xmin = 0;
  xmax = 100;
  ymin = 0;
  ymax = 100;
  fpen.setColor(QColor(0, 0, 255));
  spen.setColor(QColor(0, 255, 0));
  tpen.setColor(QColor(255, 0, 0));
}
Configuration::~Configuration() {}

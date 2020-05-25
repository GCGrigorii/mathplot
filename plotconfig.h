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

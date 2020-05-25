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
  ui->lineEdit_5->setText(QString::number(r));
  ui->lineEdit_6->setText(QString::number(r));
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

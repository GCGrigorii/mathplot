#ifndef SCHEMA_DISPLAY_H
#define SCHEMA_DISPLAY_H

#include <QDialog>

namespace Ui {
  class Schema_display;
}

class Schema_display : public QDialog
{
  Q_OBJECT

public:
  explicit Schema_display(QWidget *parent = nullptr);
  ~Schema_display();

private:
  Ui::Schema_display *ui;
};

#endif // SCHEMA_DISPLAY_H

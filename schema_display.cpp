#include "schema_display.h"
#include "ui_schema_display.h"

Schema_display::Schema_display(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Schema_display)
{
  ui->setupUi(this);
}

Schema_display::~Schema_display()
{
  delete ui;
}

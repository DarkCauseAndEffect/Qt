#ifndef IDDIALOG_H
#define IDDIALOG_H

#include <QDialog>
#include"Teacher.h"

namespace Ui {
class IdDialog;
}

class IdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IdDialog(QWidget *parent = nullptr);
    ~IdDialog();

    int Id;
    Teacher* teacher;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::IdDialog *ui;
};

#endif // IDDIALOG_H

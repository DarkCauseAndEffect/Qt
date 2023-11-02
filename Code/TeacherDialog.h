#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include"Teacher.h"
    namespace Ui {
class TeacherDialog;
}

class TeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherDialog(Teacher* teacher, QWidget *parent = nullptr);
    ~TeacherDialog();
    Teacher *teacher;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TeacherDialog *ui;
};

#endif // TEACHERDIALOG_H

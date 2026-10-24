#ifndef ADDURLDIALOG_H
#define ADDURLDIALOG_H

#include <QDialog>
#include "ui_addurlform.h"

class AddUrlDialog : public QDialog
{
    Q_OBJECT

public:
    AddUrlDialog(QWidget *parent = 0);

    QString url() const;
    QString destinationFolder() const;

public slots:    
    void setUrl();

private slots:
    void selectDestination();
    void enableOkButton();

private:
    Ui_AddURL ui;
    QString destinationDirectory;
    QString lastDirectory;
    QString lastDestinationDirectory;
};

#endif

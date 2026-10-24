#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QMetaObject>
#include "addurldialog.h"

AddUrlDialog::AddUrlDialog(QWidget *parent)
  : QDialog(parent, Qt::Sheet)
{
    ui.setupUi(this);

    /*connect(ui.browseDestination, SIGNAL(clicked()),
            this, SLOT(selectDestination()));*/
    connect(ui.urlString, SIGNAL(textChanged(QString)),
            this, SLOT(setUrl()));

    //ui.destinationFolder->setText(destinationDirectory = QDir::current().path());
    ui.urlString->setFocus();
}

void AddUrlDialog::selectDestination()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose a destination directory"),
                                                    lastDestinationDirectory);
    if (dir.isEmpty())
        return;
    lastDestinationDirectory = destinationDirectory = dir;
    //ui.destinationFolder->setText(destinationDirectory);
    enableOkButton();
}

void AddUrlDialog::enableOkButton()
{
    ui.okButton->setEnabled(!ui.urlString->text().isEmpty());
}

void AddUrlDialog::setUrl()
{
    enableOkButton();
}

QString AddUrlDialog::url() const
{
    return ui.urlString->text();
}

QString AddUrlDialog::destinationFolder() const
{
    return this->destinationDirectory;
}

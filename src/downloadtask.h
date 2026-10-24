#ifndef DOWNLOADTASK_H
#define DOWNLOADTASK_H

#include <QUrl>
#include <QFileInfo>

class DownloadTask
{
public:
    DownloadTask(QUrl url);
    QUrl url();
    QString fileName();

    void setFileSize(qint64 size);
    qint64 fileSize() const;
    QString fileSizeToString() const;

    void setAcceptRanges(bool accept);
    bool acceptRanges() const;

    void setStatus(int status);
    int status() const;

private:
    QUrl _url;
    QString _fileName;

    //Resume capability
    bool _acceptRanges;

    qint64 totalSize;

    //Percent
    int _status;
};

#endif // DOWNLOADTASK_H

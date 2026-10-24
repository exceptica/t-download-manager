#include "downloadtask.h"

DownloadTask::DownloadTask(QUrl url)
{
    this->_url = url;
    this->_fileName = QFileInfo(url.path()).fileName();
    this->_acceptRanges = false;
    this->_status = 0;
}

QUrl DownloadTask::url()
{
    return this->_url;
}

QString DownloadTask::fileName()
{
    return this->_fileName;
}

void DownloadTask::setFileSize(qint64 size)
{
    this->totalSize = size;
}

qint64 DownloadTask::fileSize() const
{
    return this->totalSize;
}

QString DownloadTask::fileSizeToString() const
{
    QString unit;
    double _size = this->totalSize;

    if (_size < 1024) {
        unit = "bytes";
    }
    else if (_size < 1024*1024) {
        _size /= 1024;
        unit = "kB";
    }
    else if (_size < 1024*1024*1024) {
        _size /= 1024*1024;
        unit = "MB";
    }
    else {
        _size /= 1024*1024*1024;
        unit = "GB";
    }

    return QString::number(_size, 'g', 3).append(" ").append(unit);
}

void DownloadTask::setAcceptRanges(bool accept)
{
    this->_acceptRanges = accept;
}

bool DownloadTask::acceptRanges() const
{
    return this->_acceptRanges;
}

void DownloadTask::setStatus(int status)
{
    this->_status = status;
}

int DownloadTask::status() const
{
    return this->_status;
}

#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class download : public QObject
{
    Q_OBJECT
public:
    explicit download(QObject *parent = nullptr);
    void doDownload(QString download_link, QString response_type);

signals:

public slots:
    void replyFinished(QNetworkReply *reply);
private:
    QString download_type;
    QNetworkAccessManager *manager;
};

#endif // DOWNLOAD_H

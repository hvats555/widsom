#include "download.h"
#include "choosebook.h"

download::download(QObject *parent) : QObject(parent)
{
}

void download::doDownload(QString download_link, QString response_type){
    download_type = response_type;
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(download_link)));
}

void download::replyFinished(QNetworkReply *reply){

    if(reply->error()){
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }else{

        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        QFile *file;

        if(download_type == "json"){
            file = new QFile("C:/wisdom/response/api_response.json");
        }else if(download_type == "image"){
            file = new QFile("C:/wisdom/images/book_cover.jpg");
        }

        if(file->open(QFile::Append)){
            file->write(reply->readAll());
            file->flush();
            file->close();
        }

        delete file;
    }
    reply->deleteLater();
}

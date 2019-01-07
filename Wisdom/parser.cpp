#include "parser.h"
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

parser::parser(QObject *parent) : QObject(parent)
{

}

void parser::parse(){
    QString filePath = "C:/wisdom/response/api_response.json";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file" << file.fileName() << "for reading:" << file.errorString();
    }

    QByteArray jsonData = file.readAll();
    if (file.error() != QFile::NoError) {
        qDebug() << QString("Failed to read from file %1, error: %2").arg(file.fileName()).arg(file.errorString());
    }

    if (jsonData.isEmpty()) {
        qDebug() << "No data was currently available for reading from file" << file.fileName();
    }

    QJsonDocument document = QJsonDocument::fromJson(jsonData);

    if (!document.isObject()) {
        qDebug() << "Document is not an object";
    }

    QJsonObject object = document.object();

    QJsonArray items = object["items"].toArray();
    QJsonObject itemObject = items.at(0).toObject();
    QJsonObject volumeInfo = itemObject["volumeInfo"].toObject();
    QJsonArray authors = volumeInfo["authors"].toArray();
    QJsonArray c = volumeInfo["categories"].toArray();
    QJsonObject imgUrl = volumeInfo["imageLinks"].toObject();


    bookTitle = volumeInfo["title"].toString();
    publisher = volumeInfo["publisher"].toString();
    publisheDate = volumeInfo["publishedDate"].toString();
    description = volumeInfo["description"].toString();
    author = authors.at(0).toString();
    pageCount = volumeInfo["pageCount"].toString();
    catagory = c.at(0).toString();
    imageLink = imgUrl["thumbnail"].toString();

    qDebug() << "Book - " <<  bookTitle;
    qDebug() << "Publisher - " << publisher;
    qDebug() << "PublishDate - " << publisheDate;
    qDebug() << "Description - " << description;
    qDebug() << "Author - " << author;
    qDebug() << "Page count - " <<  pageCount;
    qDebug() << "Category - " << catagory;
    qDebug() << "Image link - " << imageLink;
}



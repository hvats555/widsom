#ifndef PARSER_H
#define PARSER_H

#include <QObject>


class parser : public QObject
{
    Q_OBJECT
public:
    explicit parser(QObject *parent = nullptr);

    QString bookTitle;
    QString author;
    QString publisher;
    QString publisheDate;
    QString description;
    QString catagory;
    QString thumbnail;
    QString imageLink;
    QString pageCount;

    void parse();

signals:

public slots:
};

#endif // PARSER_H

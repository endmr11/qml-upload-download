#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include "islem.h"

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);

    QString secilenn;

signals:


public slots:
    void sectin(QString a);
    void secilenDosya();
    void secilenIndir(QNetworkReply *reply);


private:
    QNetworkAccessManager *manager;

};

#endif // DOWNLOADER_H

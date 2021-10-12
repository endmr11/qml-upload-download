#include "downloader.h"


Downloader::Downloader(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::secilenIndir);
}

void Downloader::sectin(QString a)
{
    secilenn=a;
    secilenDosya();
}

void Downloader::secilenDosya()
{
    QUrl url("http://eren-demir.com/ortak/"+secilenn);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void Downloader::secilenIndir(QNetworkReply *reply)
{

    if(reply->error()){

        qDebug() << "Hata";
        qDebug() << reply->errorString();
    } else {

        QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
        QString oturum = homePath.first().split(QDir::separator()).last();

        QFile *file = new QFile(oturum+"/Desktop/"+secilenn);

        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());
            file->close();
        qDebug() << "İndirme İşlemi Tamamlandı";
        }
    }
}

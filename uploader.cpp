#include "uploader.h"


Uploader::Uploader(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &Uploader::uploadFinished);
}

void Uploader::dosyaSec(QString a)
{
    m_fileName = a;
    //qDebug() << "Seçilen Dosya Yolu" << m_fileName;
    yolGonder(m_fileName);
}


void Uploader::dosyaYukle()
{

    m_fileName.replace(0,8,"");

    m_file = new QFile(m_fileName);

    qDebug() << "m_file:"<< m_file;

    QFileInfo fileInfo(*m_file);

    qDebug() << "fileInfo:"<< fileInfo;

    QUrl url("ftp://adres/public_html/ortak/" + fileInfo.fileName());

    qDebug() << "fileName:"<< fileInfo.fileName();

    url.setUserName("kullaiciadi");
    url.setPassword("sifre");
    url.setPort(21);

    if (m_file->open(QIODevice::ReadOnly))
    {
        qDebug() << "Yükleme Çalıştı";
        QNetworkReply *reply = m_manager->put(QNetworkRequest(url), m_file);
        connect(reply, &QNetworkReply::uploadProgress, this, &Uploader::uploadProgress);

    }

    dosya_name=fileInfo.fileName();

    QSqlQuery dosyEkle;
    dosyEkle.exec("INSERT INTO files VALUES(DEFAULT, '"+dosya_name+"')");

}

void Uploader::uploadFinished(QNetworkReply *reply)
{
    if (!reply->error())
    {
        m_file->close();
        m_file->deleteLater();
        reply->deleteLater();
    }
}

void Uploader::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    sureGonder(100 * bytesSent/bytesTotal);
}

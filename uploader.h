#ifndef UPLOADER_H
#define UPLOADER_H

#include <QObject>
#include "islem.h"

class Uploader : public QObject
{
    Q_OBJECT
public:
    explicit Uploader(QObject *parent = nullptr);

    QNetworkAccessManager *m_manager;
    QString m_fileName;
    QFile *m_file;
    QString dosya_name;

signals:
    void yolGonder(QString yol);
    void sureGonder(int sure);

public slots:

    void dosyaSec(QString a);
    //void veritabaniEkle(QString a, QString b, QString c);
    void dosyaYukle();
    void uploadFinished(QNetworkReply *reply);
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);

};

#endif // UPLOADER_H

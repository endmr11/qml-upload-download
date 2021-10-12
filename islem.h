#ifndef ISLEM_H
#define ISLEM_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Islem : public QObject
{
    Q_OBJECT
public:
    explicit Islem(QObject *parent = nullptr);

    void veritabaniBaglan();
    QSqlDatabase    db;


private:
    bool veritabaniAc();

signals:

};

#endif // ISLEM_H

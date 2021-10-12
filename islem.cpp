#include "islem.h"

Islem::Islem(QObject *parent) : QObject(parent)
{

}

void Islem::veritabaniBaglan()
{
        this->veritabaniAc();
}

bool Islem::veritabaniAc()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("yuklemeIndirme");
    db.setUserName("postgres");
    db.setPassword("123456789");
    if(db.open()){
        qDebug() << "Veri Tabanı Bağlantısı Başarılı";
        return true;
    } else {
        return false;
    }

}

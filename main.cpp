#include <QGuiApplication>
#include <QQmlApplicationEngine>

//VERİTABANI BAĞLAMAK İÇİN
#include <QQmlContext>
#include "islem.h"
#include "uploader.h"
#include "downloader.h"

#include "listmodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //VERİTABANI YER TUTMA
    Islem database;
    database.veritabaniBaglan();

    Uploader upload;
    Downloader download;

    ListModel *listmodel = new ListModel();

    //VERİTABANI YER TUTMA


    //VERİTABANI BAĞLAMA KODLARI BU ARALIĞA YAZILACAK
    engine.rootContext()->setContextProperty("yukleme", &upload);
    engine.rootContext()->setContextProperty("indirme", &download);
    //VERİTABANI BAĞLAMA KODLARI BU ARALIĞA YAZILACAK

    engine.rootContext()->setContextProperty("myModel", listmodel);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>

class ListModel : public QSqlQueryModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        nameRole,
    };

    explicit ListModel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;


protected:

    QHash<int, QByteArray> roleNames() const;

signals:

    void ortalamaGoster(float a,float b);

public slots:
    void modelGuncelle();
};

#endif // LISTMODEL_H

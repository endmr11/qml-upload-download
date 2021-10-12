#include "listmodel.h"
#include "islem.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->modelGuncelle();
}

QVariant ListModel::data(const QModelIndex & index, int role) const {

    int columnId = role - Qt::UserRole - 1;

    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> ListModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[IdRole] = "filesidRole";
    roles[nameRole] = "filesnameRole";
    return roles;
}


void ListModel::modelGuncelle()
{
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT files_id,files_name  FROM files ORDER BY files_id DESC");
}

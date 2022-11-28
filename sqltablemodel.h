#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
public:
    SqlTableModel(QObject * parent = 0, QSqlDatabase db = QSqlDatabase());
    ~SqlTableModel();
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
};

#endif // SQLTABLEMODEL_H

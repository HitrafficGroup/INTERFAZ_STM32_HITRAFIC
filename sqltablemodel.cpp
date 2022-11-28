#include "sqltablemodel.h"
#include <QColor>
#include <QFont>

#include <qsqldriver.h>
#include <qsqlerror.h>
#include <qsqlfield.h>
#include <qsqlindex.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <qsqlresult.h>



SqlTableModel::SqlTableModel(QObject * parent, QSqlDatabase db) : QSqlTableModel(parent,db)
{
}

SqlTableModel::~SqlTableModel()
{
}

QVariant SqlTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value  = QSqlTableModel::data(index,role);
    if(Qt::TextAlignmentRole == role)
    {
        return int(Qt::AlignCenter | Qt::AlignHCenter);
    }

    return value;
}

/*
QVariant SqlTableModel::data(const QModelIndex &idx, int role) const
{
    QVariant value  = QSqlTableModel::data(idx,role);
    if(Qt::TextAlignmentRole == role)
    {
        value   = int(Qt::AlignCenter | Qt::AlignHCenter);
        return value;
    }
    if(Qt::ForegroundRole == role)
    {
        if(3 == idx.column())
            return QVariant(QColor(255,144,144));
    }
    if(Qt::FontRole == role)
    {
        if(3 == idx.column())
        {
            QFont font;
            font.setBold(true);
            return QVariant(font);
        }
    }
    return value;
}
*/

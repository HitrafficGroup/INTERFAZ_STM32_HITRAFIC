#include "readonlydelegate.h"


readOnlyDelegate::readOnlyDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *readOnlyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    return NULL;
}


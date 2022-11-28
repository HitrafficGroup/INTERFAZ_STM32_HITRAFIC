#ifndef READONLYDELEGATE_H
#define READONLYDELEGATE_H


#include <QItemDelegate>
#include <QStyledItemDelegate>

class readOnlyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    readOnlyDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget*parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // READONLYDELEGATE_H

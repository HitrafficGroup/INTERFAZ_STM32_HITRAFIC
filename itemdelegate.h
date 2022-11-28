#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QItemDelegate>

class ItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate();
private:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMDELEGATE_H

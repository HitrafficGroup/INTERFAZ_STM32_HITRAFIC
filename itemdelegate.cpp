#include "itemdelegate.h"

ItemDelegate::ItemDelegate()
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    QStyleOptionViewItem viewOption(option);
    //高亮显示与普通显示时的前景色一致（即选中行和为选中时候的文字颜色一样）
    //viewOption.palette.setColor(QPalette::HighlightedText, index.data(Qt::ForegroundRole).value<QColor>());
//    viewOption.palette.setColor(QPalette::Background, index.data(Qt::BackgroundRole).value<QColor>());
//    QItemDelegate::paint(painter, viewOption, index);

    //重新QItemDelegate的paint方式。
    QStyleOptionViewItem coption = option;
    coption.state &= ~QStyle::State_Selected;
    QItemDelegate::paint(painter, coption, index);
    //if(option.state & QStyle::State_Selected)
    //coption->(option.rect, QColor(165, 207, 241, 128));
}




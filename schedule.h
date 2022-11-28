#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>
#include <QPushButton>





class schedule : public QWidget
{
    Q_OBJECT
public:
    explicit schedule(QWidget *parent = 0);

signals:

public slots:

private:
    QPushButton *btn;

};

#endif // SCHEDULE_H

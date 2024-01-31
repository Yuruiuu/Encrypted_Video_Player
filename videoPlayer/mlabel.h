#ifndef MLABEL_H
#define MLABEL_H

#include <QLabel>



class MyLabel(QLabel* parent):QLabel(parent)
{
    Q_OBJECT
public:
    MyLabel();
};

#endif // MLABEL_H

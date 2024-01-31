#include "widget.h"
#include "ui_widget.h"

#include <QCloseEvent>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_show(const QString &nick, const QByteArray &head)
{

}



#include "infoform.h"
#include "ui_infoform.h"


InfoForm::InfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoForm)
{
    ui->setupUi(this);

}

InfoForm::~InfoForm()
{
    delete ui;
}

InfoForm &InfoForm::set_text(const QString &text, const QString &button)
{
    ui->connectButton->setText(button);
    ui->textLb->setText(text);
    return *this;
}

void InfoForm::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos() - position);
}

void InfoForm::mousePressEvent(QMouseEvent *event)
{
    position = event->globalPos() - this->pos();
}

void InfoForm::mouseReleaseEvent(QMouseEvent *event)
{

}
void InfoForm::on_closeButton_released()
{
    emit closed();
    hide();
}


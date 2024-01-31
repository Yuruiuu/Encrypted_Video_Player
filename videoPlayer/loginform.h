#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include "infoform.h"
#include "widget.h"
#include <time.h>
#include <QPixmap>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QCryptographicHash>
#include <QMouseEvent>
#include <recordfile.h>
#include <QtNetwork/QNetworkAccessManager>




namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void login(const QString& nick, const QByteArray& head);

private slots:
    void on_loginButton_released();
    void slots_login_request_finshed(QNetworkReply* reply);

protected:
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);



private:
    bool check_login(const QString& user, const QString& pwd);
    void load_config();
private:
    Ui::LoginForm *ui;
    QPoint position;//用于标记鼠标移动位置
    InfoForm info;
    RecordFile* record;
    QNetworkAccessManager* net;
};

#endif // LOGINFORM_H

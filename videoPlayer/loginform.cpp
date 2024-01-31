#include "loginform.h"
#include "ui_loginform.h"
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <time.h>


const char* MD5_KEY = "*&^%$#@b.v+h-b*g/h@n!h#n$d^ssx,.kl<kl";
const char* HOST = "http://127.0.0.1:19527";
bool LOGIN_STATUS = false;

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    record = new RecordFile("data.json");
    this->setWindowFlag(Qt::FramelessWindowHint);//无头窗口
    ui->nameEdit->setPlaceholderText(u8"用户名/手机号/邮箱");
    ui->nameEdit->setFrame(false);
    ui->nameEdit->installEventFilter(this);
    ui->passwdEdit->setPlaceholderText(u8"填写密码");
    ui->passwdEdit->setFrame(false);
    ui->passwdEdit->setEchoMode(QLineEdit::Password);
    ui->passwdEdit->installEventFilter(this);
    //connect(net, SIGNAL(finished(QNetworkReply*)),
    //        this, SLOT(slots_login_request_finshed(QNetworkReply*)));
    info.setWindowFlag(Qt::FramelessWindowHint);
    info.setWindowModality(Qt::ApplicationModal);
    QSize sz = size();
    info.move((sz.width() - info.width()) / 2, (sz.height() - info.height()) / 2);
    load_config();
}

LoginForm::~LoginForm()
{
    delete record;
    delete ui;
    delete net;
}


void LoginForm::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos() - position);
}

void LoginForm::mousePressEvent(QMouseEvent *event)
{
    position = event->globalPos() - this->pos();
}

void LoginForm::mouseReleaseEvent(QMouseEvent *event)
{

}

bool LoginForm::check_login(const QString &user, const QString &pwd)
{
    /*
    QCryptographicHash md5(QCryptographicHash::Md5);
    QNetworkRequest request;
    QString url = QString(HOST) + "/login?";
    QString salt = QString::number(QRandomGenerator::global()->bounded(10000, 99999));
    QString time = getTime();
    qDebug().nospace()<< __FILE__ << "(" << __LINE__ << "):" <<time + MD5_KEY + pwd + salt;
    md5.addData((time + MD5_KEY + pwd + salt).toUtf8());
    QString sign = md5.result().toHex();
    url += "time=" + time + "&";
    url += "salt=" + salt + "&";
    url += "user=" + user + "&";
    url += "sign=" + sign;
    //qDebug() << url;
    request.setUrl(QUrl(url));
    record->config()["password"] = ui->pwdEdit->text();
    record->config()["user"] = ui->nameEdit->text();
    this->setEnabled(false);
    net->get(request);
    return true;*/
    LOGIN_STATUS = true;
    emit login(record->config()["user"].toString(), QByteArray());
    hide();
    char tm[64] = "";
    time_t t;
    ::time(&t);
    strftime(tm, sizeof(tm), "%Y-%m-%d %H:%M:%S", localtime(&t));
    record->config()["date"] = QString(tm);//更新登录时间
    record->save();
    return false;
}

void LoginForm::load_config()
{

}

void LoginForm::on_loginButton_released()
{
    if(ui->loginButton->text()==u8"取消自动登录"){

        //如果取消自动登录

    }
    else {
        QString user = ui->nameEdit->text();
        //检查用户名的有效性
        if(user.size()==0||user==u8"用户名/手机号/邮箱"){
            info.set_text(u8"用户不能为空\r\n请输入用户名", u8"确认").show();//因为set_text返回了自身，所以可以接着show
            ui->nameEdit->setFocus();
            return;
        }
        //检查密码的有效性
        QString pwd = ui->passwdEdit->text();
        if(pwd.size()==0||pwd==u8"填写密码"){
            info.set_text(u8"密码不能为空\r\n请输入密码", u8"确认").show();
            ui->passwdEdit->setFocus();
            return;
        }
        check_login(user, pwd);
    }
}

void LoginForm::slots_login_request_finshed(QNetworkReply *reply)
{

}


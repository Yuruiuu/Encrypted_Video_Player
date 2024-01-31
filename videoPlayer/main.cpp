#include "widget.h"

#include <QApplication>
#include <QObject>
#include "loginform.h"

int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");
    Widget w;
    LoginForm login;
    w.hide();
    login.show();

    login.connect(&login, SIGNAL(login(const QString&, const QByteArray&)),
                  &w, SLOT(on_show(const QString&, const QByteArray&)));
    //Qt::connect(&login,&LoginForm::login,&w,&Widget::on_show);

    return a.exec();
}

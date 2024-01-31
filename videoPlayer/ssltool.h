#ifndef SSLTOOL_H
#define SSLTOOL_H

#include <QByteArray>



class SslTool
{
public:
    SslTool();
    //rsa加密
    QByteArray rsaEncode(const QByteArray& buffer);
    //rsa解密
    QByteArray rsaDecode(const QByteArray& input);
};

#endif // SSLTOOL_H

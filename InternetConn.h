#ifndef INTERNETCONN_H
#define INTERNETCONN_H
#include <QString>
#include <QDesktopServices>


class InternetConn{
public:
    static void linkOpen(QString link);

private:
    static QString linkBuild(QString link);
};

#endif // INTERNETCONN_H

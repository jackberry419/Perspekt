#include "InternetConn.h"
#include "Parameter.h"
#include <QDebug>
#include <QUrl>

void InternetConn::linkOpen(QString link){
    link= linkBuild(link);
    qDebug()<<link;
    QDesktopServices::openUrl(QUrl(link));
}

QString InternetConn::linkBuild(QString link){
    if(BookRange::language==CHINESE){
        link = "https://dict.leo.org/chde/index_de.html#/search=" + link + "&searchLoc=0&resultOrder=basic&multiwordShowSingle=on";
    }
    // Otherwise use English
    else{
        link = "https://dict.leo.org/ende/index_de.html#/search=" + link + "&searchLoc=0&resultOrder=basic&multiwordShowSingle=on";
    }
    return link;
}

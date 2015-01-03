#include "Exercise.h"
#include "Parameter.h"
#include <QDebug>
#include <QFile>


Exercise::~Exercise(){
     qDebug()<<"desconstructor is called";
}

int Exercise::reload(){
    qDebug()<<"nothing will happen here";
    return 1;
}


/*Verben, Public Methods*/

int Verben::initial(){
    crtIndex = 0;
    QFile file("Verben.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Cannot find the file Verben.txt";
        return EStatus::error;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList list = line.split(";");
        VerbenList vList;
        vList.infinitiv = list[0];
        vList.praesens = list[1];
        vList.praeteritum = list[2];
        vList.perfekt = list[3];
        verbenList.append(vList);
    }

    displayList.append(verbenList[crtIndex].infinitiv);
    displayList.append(verbenList[crtIndex].praesens);
    displayList.append(verbenList[crtIndex].praeteritum);
    displayList.append(verbenList[crtIndex].perfekt);
    return EStatus::normal;
}


int Verben::getMaxIndex(){
    return verbenList.length()-1;
}

void Verben::deleteItem(int index){
    verbenList.removeAt(index);
}

void Verben::updateDisplayList(){
    displayList[0]=verbenList[crtIndex].infinitiv;
    displayList[1]=verbenList[crtIndex].praesens;
    displayList[2]=verbenList[crtIndex].praeteritum;
    displayList[3]=verbenList[crtIndex].perfekt;
}

VerbenList Verben::getData(int index){
    return verbenList[index];
}


int Wortschatz::getMaxIndex(){
    return wortschatzList.length()-1;
}

int Wortschatz::initial(){
    crtIndex = 0;
    QList<QString> kapitelList;
    kapitelList=getKapitelList();
    if(kapitelList.isEmpty()){
        qDebug()<<"kapitelList is empty";
        return EStatus::error;
    }
    QList<QString>::iterator i;

    for(i=kapitelList.begin();i!=kapitelList.end();i++){
        QFile file(*i);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"Cannot find the file " + *i;
            return EStatus::error;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList list = line.split(";");
            WortschatzList wlist;
            wlist.word = list[0];
            wlist.explain = list[1];
            wortschatzList.append(wlist);
        }
        qDebug()<<wortschatzList.length();
    }

    displayList.append(wortschatzList[crtIndex].word);
    displayList.append(wortschatzList[crtIndex].explain);
    return EStatus::normal;
}

int Wortschatz::reload(){
    qDebug()<<"reload will happen here";
    wortschatzList.clear();
    displayList.clear();
    return initial();
}

void Wortschatz::deleteItem(int index){
    wortschatzList.removeAt(index);
}

WortschatzList Wortschatz::getData(int index){
    return wortschatzList[index];
}

void Wortschatz::updateDisplayList(){
    displayList[0] = wortschatzList[crtIndex].word;
    displayList[1] = wortschatzList[crtIndex].explain;
}

/********Wortschatz Private*******/

/*getKapitelList() return a list of txt files*/
QList<QString> Wortschatz::getKapitelList(){
    QList<QString> kapitelList;
    int kp_num = BookRange::kapitel_num;
    int checker=1;
    for(int i=1;i<=10;i++){
        if(checker&kp_num){
            kapitelList.append("Wortschazt"+QString::number(i)+".txt");
            qDebug()<<"Wortschazt"+QString::number(i)+".txt";
        }
        checker = checker<<1;
    }
    return kapitelList;
}

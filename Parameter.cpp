#include "Parameter.h"
#include <QDebug>

int BookRange::kapitel_num = KAPITEL1;
Language BookRange::language = CHINESE;

void BookRange::readRange(){

}

void BookRange::setChapterNum(int num){
    kapitel_num = num|kapitel_num;
}

bool BookRange::clearChapterNum(int num){
    if (~num & (kapitel_num)){
        kapitel_num = (~num) & kapitel_num;
        return true;
    }
    else{
        qDebug()<<"you must select at least one chapter";
        return false;
    }
}


#include "Player.h"
#include "Parameter.h"
#include <QDebug>


int Player::getCurrentIndex(){
    return crtIndex;
}

int WordPlayer::startToPlay(){
    int status;
    exercise = new Wortschatz;
    status = exercise->initial();
    if (status==EStatus::normal){
        crtIndex = 0;
        maxIndex = exercise->getMaxIndex();
        WortschatzList w = exercise->getData(crtIndex);
        DisplayElement dis;
        dis.toDisplay = true;
        dis.content = w.word;
        displayList.append(dis);
        dis.content = w.explain;
        displayList.append(dis);
        emit updateUI();
    }

    return status;
}

void WordPlayer::deleteItem(){
    exercise->deleteItem(crtIndex);
    if(crtIndex==maxIndex){
        crtIndex=0;
    }
    maxIndex--;
    WortschatzList w = exercise->getData(crtIndex);
    displayList[0].content = w.word;
    displayList[0].toDisplay = true;
    displayList[1].content = w.explain;
    displayList[1].toDisplay = true;
    emit updateUI();
}

void WordPlayer::playLast(){
    if (crtIndex == 0){
        crtIndex = maxIndex;
    }
    else{
        crtIndex--;
    }
    WortschatzList w = exercise->getData(crtIndex);
    displayList[0].content = w.word;
    displayList[0].toDisplay = true;
    displayList[1].content = w.explain;
    displayList[1].toDisplay = true;
    emit updateUI();
}

void WordPlayer::playNext(){
    if (crtIndex == maxIndex){
        crtIndex = 0;
    }
    else{
        crtIndex++;
    }
    WortschatzList w = exercise->getData(crtIndex);
    displayList[0].content = w.word;
    displayList[0].toDisplay = true;
    displayList[1].content = w.explain;
    displayList[1].toDisplay = true;
    emit updateUI();
}

void WordPlayer::changeMode(){}


int VerbenPlayer::startToPlay(){
    int status;
    exercise = new Verben;
    status = exercise->initial();
    if (status==EStatus::normal){
        crtIndex = 0;
        maxIndex = exercise->getMaxIndex();
        VerbenList v = exercise->getData(crtIndex);
        DisplayElement dis;
        dis.toDisplay = true;
        dis.content = v.infinitiv;
        displayList.append(dis);
        dis.content = v.praesens;
        displayList.append(dis);
        dis.content = v.praeteritum;
        displayList.append(dis);
        dis.content = v.perfekt;
        displayList.append(dis);
        emit updateUI();
    }
    return status;
}

void VerbenPlayer::playNext(){
    if (crtIndex == maxIndex){
        crtIndex = 0;
    }
    else{
        crtIndex++;
    }
    VerbenList v = exercise->getData(crtIndex);
    displayList[0].content = v.infinitiv;
    displayList[0].toDisplay = true;
    displayList[1].content = v.praesens;
    displayList[1].toDisplay = true;
    displayList[2].content = v.praeteritum;
    displayList[2].toDisplay = true;
    displayList[3].content = v.perfekt;
    displayList[3].toDisplay = true;
    emit updateUI();
}

void VerbenPlayer::playLast(){
    if (crtIndex == 0){
        crtIndex = maxIndex;
    }
    else{
        crtIndex--;
    }
    VerbenList v = exercise->getData(crtIndex);
    displayList[0].content = v.infinitiv;
    displayList[0].toDisplay = true;
    displayList[1].content = v.praesens;
    displayList[1].toDisplay = true;
    displayList[2].content = v.praeteritum;
    displayList[2].toDisplay = true;
    displayList[3].content = v.perfekt;
    displayList[3].toDisplay = true;
    emit updateUI();
}

void VerbenPlayer::deleteItem(){
    exercise->deleteItem(crtIndex);
    if(crtIndex==maxIndex){
        crtIndex=0;
    }
    maxIndex--;
    VerbenList v = exercise->getData(crtIndex);
    displayList[0].content = v.infinitiv;
    displayList[0].toDisplay = true;
    displayList[1].content = v.praesens;
    displayList[1].toDisplay = true;
    displayList[2].content = v.praeteritum;
    displayList[2].toDisplay = true;
    displayList[3].content = v.perfekt;
    displayList[3].toDisplay = true;
    emit updateUI();
}

void VerbenPlayer::changeMode(){}




#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QString>
#include <QObject>
#include "Exercise.h"

struct DisplayElement{
   QString content;
   bool toDisplay;
};

class Player:public QObject{
Q_OBJECT
public:
    QString getDisplayElement(int index);
    virtual int startToPlay()=0;
    virtual void playLast()=0;
    virtual void playNext()=0;
    virtual void deleteItem()=0;
    virtual void changeMode()=0;
    int getCurrentIndex();
    QList<DisplayElement> displayList;
signals:
    void updateUI();
protected:
    int crtIndex;
    int maxIndex;

};

class WordPlayer:public Player{
public:
    int startToPlay();
    void playLast();
    void playNext();
    void deleteItem();
    void changeMode();
private:
    Wortschatz* exercise;
};

class VerbenPlayer:public Player{
public:
    int startToPlay();
    void playLast();
    void playNext();
    void deleteItem();
    void changeMode();
private:
    Verben* exercise;
};

#endif // PLAYER_H

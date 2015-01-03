#ifndef EXERCISE_H
#define EXERCISE_H

#include <QMainWindow>
#include <QString>
#include <QObject>

class Exercise:public QObject{
Q_OBJECT
public:
    virtual ~Exercise();
    virtual int initial()=0;
    virtual void deleteItem(int crtIndex)=0;
    virtual int reload();
    virtual int getMaxIndex()=0;
signals:
    void updateUI();
protected:
    QList<QString> displayList;

};

struct VerbenList{
    QString infinitiv;
    QString praesens;
    QString praeteritum;
    QString perfekt;
};

class Verben:public Exercise{

public:
    int initial();
    void deleteItem(int crtIndex);
    int getMaxIndex();
    VerbenList getData(int index);

private:
    QList<VerbenList> verbenList;
    void updateDisplayList();
    int crtIndex;
};

struct WortschatzList{
    QString word;
    QString explain;
};

class Wortschatz:public Exercise{
public:
   int initial();
   int reload();
   void deleteItem(int crtIndex);
   int getMaxIndex();
   WortschatzList getData(int index);
private:
   QList<WortschatzList> wortschatzList;
   void updateDisplayList();
   QList<QString> getKapitelList();
   int crtIndex;
};

#endif // EXERCISE_H

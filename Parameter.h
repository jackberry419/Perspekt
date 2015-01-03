#ifndef PARAMETER_H
#define PARAMETER_H

#define KAPITEL1  0b0000000001
#define KAPITEL2  0b0000000010
#define KAPITEL3  0b0000000100
#define KAPITEL4  0b0000001000
#define KAPITEL5  0b0000010000
#define KAPITEL6  0b0000100000
#define KAPITEL7  0b0001000000
#define KAPITEL8  0b0010000000
#define KAPITEL9  0b0100000000
#define KAPITEL10 0b1000000000

enum Language{CHINESE,ENGLISH,GERMAN};

class EStatus{
public:
    static const int normal = 1;
    static const int error = -1;
};


class BookRange{
public:
    static int kapitel_num;
    static void setChapterNum(int num);
    static bool clearChapterNum(int num);
    static Language language;
private:
    static void readRange();
};

#endif // PARAMETER_H



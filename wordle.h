#ifndef WORDLE_H
#define WORDLE_H
#include "QLabel"
class wordle: public QLabel{
public :
    wordle();
    bool checker1(char);
    bool checker2(char);
private :
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QLabel * label6;
    QLabel * label7;
    QLabel * label8;
};

#endif // WORDLE_H

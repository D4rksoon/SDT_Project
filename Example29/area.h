#ifndef AREA_H
#define AREA_H

#include "figura.h"

class Area : public QWidget
{
    int myTimer;
    float alpha;

public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;

protected:

    void paintEvent(QPaintEvent *event); //Событие отрисовки, вызывается при отрисовке виджета
    void timerEvent(QTimerEvent *event); //Генерируется по истечении установленного интервала запуска таймера
    void showEvent(QShowEvent *event); //Событие, которое отправляется при отображении виджета
    void hideEvent(QHideEvent *event); //Событие, которое отправляется при скрытии виджета
};

#endif // AREA_H

#include "widget.h"
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Счетчик");
    label1 = new QLabel("Cчет по 1");
    label2 = new QLabel("Cчет по 5");
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);
    calcButton=new QPushButton("+1", this);
    exitButton=new QPushButton("Выход", this);

    layout1 = new QHBoxLayout();
    layout2 = new QHBoxLayout();
    layout3 = new QHBoxLayout();
    layout4 = new QVBoxLayout(this);

    if(!layout1 and !layout2 and !layout3 and !layout4){
        std::cerr << "Memmory error";
    }
    else{
        layout1->addWidget(label1);
        layout1->addWidget(label2);

        layout2->addWidget(edit1);
        layout2->addWidget(edit2);

        layout3->addWidget(calcButton);
        layout3->addWidget(exitButton);

        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);
    }




    connect(calcButton, &QPushButton::clicked, edit1, &Counter::add_one);

    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);

    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);
}

Widget::~Widget()
{
}


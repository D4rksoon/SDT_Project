#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Обработка событий");
    area = new Area( this );
    btn = new QPushButton("Завершить", this);
    layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &QWidget::close);
}

Widget::~Widget()
{
}


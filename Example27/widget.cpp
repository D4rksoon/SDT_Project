#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число:");
    inputEdit = new QLineEdit("", this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputLabel = new QLabel("Результат:");
    outputEdit = new QLineEdit("", this);

    nextButton = new QPushButton("Следующее");
    exitButton = new QPushButton("Выход");


    vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);

    connect(nextButton, &QPushButton::clicked, this, &Widget::begin);

    connect(inputEdit, &QLineEdit::returnPressed, this, &Widget::calc);
}

void Widget::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget::calc()
{
    bool Ok = true;
    float result, doubleValue;
    QString str = inputEdit->text();
    doubleValue = str.toDouble(&Ok);
    if(Ok){
        result = doubleValue * doubleValue;
        str.setNum(result);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else{
        if(!str.isEmpty()){
            QMessageBox::information(this, "Возведение в квадрат", "Введено неверное значение");
        }
    }

}

Widget::~Widget()
{
}

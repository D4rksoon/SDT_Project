#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget * parent = nullptr)
    : QLineEdit(contents, parent){}

signals:
    void tick_signal();

public slots:
    void add_one()
    {
        QString str = text();
        int intValue = str.toInt();
        intValue++;
        str.setNum(intValue);
        setText(str);
        if(intValue != 0 and intValue % 5 == 0) emit tick_signal();
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    QLabel *label1;
    QLabel *label2;
    QPushButton *calcButton;
    QPushButton *exitButton;
    Counter *edit1;
    Counter *edit2;
    QHBoxLayout *layout1;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QVBoxLayout *layout4;
};



#endif // WIDGET_H

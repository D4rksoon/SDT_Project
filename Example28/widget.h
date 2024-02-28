#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

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
};

class Counter : public QLineEdit
{
public:
    Counter(const QString & contents, QWidget * parent = nullptr)
    : QLineEdit(content, parent){}
signals:
    void tick_signal();

public slots:
    void add_one()
    {
        QString str = text();
        int intValue = str.toInt();
        if(intValue != 0 and intValue % 5 == 0) emit tick_signal();
        intValue++;
        str.setNum(intValue);
        setText(str);
    }
};

#endif // WIDGET_H

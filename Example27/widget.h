#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextCodec>
#include <QFrame>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QValidator>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:

protected:
    QVBoxLayout *vLayout;
    QTextCodec *codec;
    QFrame *frame;
    QLabel *inputLabel;
    QLabel *outputLabel;
    QLineEdit *inputEdit;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;


};

class StrValidator : public QValidator
{
public:
    StrValidator(QObject *parent) : QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable;
    }
};

#endif // WIDGET_H

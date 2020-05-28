#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>
#include "widget2.h"
#include "widget3.h"
#include "widget4.h"
#include "widget5.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //画背景图
    void paintEvent(QPaintEvent *);

   //其他窗口

    QComboBox * box1;
    Widget2 * win2=NULL;
    Widget3 * win3=NULL;
    Widget4 * win4=NULL;
    Widget5 * win5=NULL;



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

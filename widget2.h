#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QComboBox>
#include "widget3.h"
namespace Ui {
class Widget2;
}

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = nullptr);
    ~Widget2();
    //画背景图
    void paintEvent(QPaintEvent *);
    QComboBox * box1;
    Widget3 * win3=NULL;
    Widget4 * win4=NULL;

private:
    Ui::Widget2 *ui;
signals:
    void back2();
    void to23();
    void to25();

};

#endif // WIDGET2_H

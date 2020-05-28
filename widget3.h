#ifndef WIDGET3_H
#define WIDGET3_H

#include <QWidget>
#include <QComboBox>
#include "widget4.h"
namespace Ui {
class Widget3;
}

class Widget3 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget3(QWidget *parent = nullptr);
    ~Widget3();
    //画背景图
    void paintEvent(QPaintEvent *);

    QComboBox * box1;
    Widget4 * win4=NULL;

signals:
    void back31();
    void back32();


private:
    Ui::Widget3 *ui;


};

#endif // WIDGET3_H

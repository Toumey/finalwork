#ifndef WIDGET4_H
#define WIDGET4_H

#include <QWidget>
#include <QComboBox>
namespace Ui {
class Widget4;
}

class Widget4 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget4(QWidget *parent = nullptr);
    ~Widget4();
    //画背景图
    void paintEvent(QPaintEvent *);
     QComboBox * box1;
     QComboBox * box2;

private:
    Ui::Widget4 *ui;

signals:
    void back41();
    void back42();
    void back43();

};

#endif // WIDGET4_H

#ifndef WIDGET5_H
#define WIDGET5_H

#include <QWidget>

namespace Ui {
class Widget5;
}

class Widget5 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget5(QWidget *parent = nullptr);
    ~Widget5();
    //画背景图
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget5 *ui;

signals:
    void back51();
    void back52();
    void back53();
};

#endif // WIDGET5_H

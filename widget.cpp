#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QPainter>
#include <QLayout>
#include <QPushButton>
#include <QtCore/qmath.h>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口部分显示
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    //影藏第二部分
    ui->groupBox_2->hide();
    //设置图标
    setWindowIcon(QIcon(":/image/houseicon.png"));

    // 设置标题
    setWindowTitle("房贷计算器");

    //提示文字
     ui->lineEdit1->setPlaceholderText("请输入房屋单价");
     ui->lineEdit2->setPlaceholderText("请输入房屋面积");
     //限制用户输入
      ui->lineEdit1->setValidator(new QIntValidator(0,999999999,this));
       ui->lineEdit2->setValidator(new QIntValidator(0,999999999,this));

       //将groupbox的边框去除
           ui->groupBox->setStyleSheet("QGroupBox{border:none}");
           ui->groupBox_2->setStyleSheet("QGroupBox{border:none}");

     //设置清空重置按钮的功能
         connect(ui->btn2,&QPushButton::clicked,[=](){
             int a = QMessageBox::question(this,"确认操作","是否要清空重置？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
             if(a==QMessageBox::Yes)
             {
             this->ui->lineEdit1->clear();
             this->ui->lineEdit2->clear();
             ui->groupBox_2->hide();
             }
         });

    //贷款类别
    ui->comboBox1->addItem("商业贷款");
    ui->comboBox1->addItem("公积金贷款");
    ui->comboBox1->addItem("组合型贷款");
    ui->comboBox1->setCurrentIndex(0);

    //公积金类型
    win2 = new Widget2;
    win3 = new Widget3;
    connect(ui->comboBox1,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==1)
        {
            win2->setGeometry(this->geometry());
            this->close();
            win2->show();
            ui->comboBox1->setCurrentIndex(0);
        }
        else if(index==2)
        {
            win3->setGeometry(this->geometry());
            this->close();
            win3->show();
            ui->comboBox1->setCurrentIndex(0);
        }
    });



    //计算方式
    ui->comboBox2->addItem("根据面积、单价计算");
    ui->comboBox2->addItem("根据贷款总额计算");
    ui->comboBox2->setCurrentIndex(0);


    //1-4
    win4 = new Widget4;
    connect(ui->comboBox2,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==1)
        {
            win4->setGeometry(this->geometry());
            this->close();
            win4->show();
            ui->comboBox2->setCurrentIndex(0);
            ui->comboBox1->setCurrentIndex(0);

        }
    });

    //2-3
    connect(win2,&Widget2::to23,[=](){
        win3->setGeometry(win2->geometry());
        win2->close();
        win3->show();
    });

    //2-5
    win5 = new Widget5;
    connect(win2,&Widget2::to25,[=](){
        win5->setGeometry(win2->geometry());
        win2->close();
        win5->show();
    });


    //按揭成数
    ui->comboBox3->addItem("8成");
    ui->comboBox3->addItem("7.5成");
    ui->comboBox3->addItem("7成");
    ui->comboBox3->addItem("6.5成");
    ui->comboBox3->addItem("6成");
    ui->comboBox3->addItem("5.5成");
    ui->comboBox3->addItem("5成");
    ui->comboBox3->addItem("4.5成");
    ui->comboBox3->addItem("4成");
    ui->comboBox3->addItem("3.5成");
    ui->comboBox3->addItem("3成");
    ui->comboBox3->addItem("2.5成");
    ui->comboBox3->addItem("2成");

    //按揭年数
    ui->comboBox4->addItem("25年（300期）");
    ui->comboBox4->addItem("24年（288期）");
    ui->comboBox4->addItem("23年（276期）");
    ui->comboBox4->addItem("22年（264期）");
    ui->comboBox4->addItem("21年（252期）");
    ui->comboBox4->addItem("20年（240期）");
    ui->comboBox4->addItem("19年（228期）");
    ui->comboBox4->addItem("18年（216期）");
    ui->comboBox4->addItem("17年（204期）");
    ui->comboBox4->addItem("16年（192期）");
    ui->comboBox4->addItem("15年（180期）");
    ui->comboBox4->addItem("14年（168期）");
    ui->comboBox4->addItem("13年（156期）");
    ui->comboBox4->addItem("12年（144期）");
    ui->comboBox4->addItem("11年（132期）");
    ui->comboBox4->addItem("10年（120期）");
    ui->comboBox4->addItem("9年（108期）");
    ui->comboBox4->addItem("8年（96期）");
    ui->comboBox4->addItem("7年（84期）");
    ui->comboBox4->addItem("6年（72期）");
    ui->comboBox4->addItem("5年（60期）");
    ui->comboBox4->addItem("4年（48期）");
    ui->comboBox4->addItem("3年（36期）");
    ui->comboBox4->addItem("2年（24期）");
    ui->comboBox4->addItem("1年（12期）");

    //商贷利率
    ui->comboBox5->addItem("20年3月20日贷款市场报价率(LPR)");
    ui->comboBox5->addItem("19年9月20日贷款市场报价率(LPR)");
    ui->comboBox5->addItem("15年10月24日基准利率");
    ui->comboBox5->addItem("15年8月26日基准利率");
    ui->comboBox5->addItem("15年6月28日基准利率");
    ui->comboBox5->addItem("15年5月11日基准利率");
    ui->comboBox5->addItem("15年3月1日基准利率");
    ui->comboBox5->addItem("14年11月22日基准利率");
    ui->comboBox5->addItem("12年7月6日基准利率");
    ui->comboBox5->addItem("12年6月8日基准利率");

    connect(ui->comboBox5,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==1)
        {
          ui->lineEdit3->setText("4.85");
        }
        else if(index==2)
        {
           ui->lineEdit3->setText("4.9");
        }
        else if(index==3)
        {
           ui->lineEdit3->setText("5.15");
        }
        else if(index==4)
        {
           ui->lineEdit3->setText("5.4");
        }
        else if(index==5)
        {
           ui->lineEdit3->setText("5.65");
        }
        else if(index==6)
        {
           ui->lineEdit3->setText("5.9");
        }
        else if(index==7)
        {
           ui->lineEdit3->setText("6.15");
        }
        else if(index==8)
        {
           ui->lineEdit3->setText("6.55");
        }
        else if(index==9)
        {
           ui->lineEdit3->setText("6.8");
        }

    });



    //设置单选按钮 默认值
    ui->rbtn1->setChecked(true);

    //返回2-1
    connect(win2,&Widget2::back2,[=](){
            this->setGeometry(win2->geometry());
            win2->close();
            this->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });


    //返回3-1
    connect(win3,&Widget3::back31,[=](){
            this->setGeometry(win3->geometry());
            win3->close();
            this->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });


    //返回3-2
    connect(win3,&Widget3::back32,[=](){
            this->setGeometry(win3->geometry());
            win3->close();
            win2->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });
    //返回4-1
    connect(win4,&Widget4::back41,[=](){
            this->setGeometry(win4->geometry());
            win4->close();
            this->show();
            ui->comboBox2->setCurrentIndex(0);
            ui->comboBox1->setCurrentIndex(0);

        });
    //4-2
    connect(win4,&Widget4::back42,[=](){
            this->setGeometry(win4->geometry());
            win4->close();
            win2->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });

    //4-3
    connect(win4,&Widget4::back43,[=](){
            this->setGeometry(win4->geometry());
            win4->close();
            win3->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });

    //返回5-1
    connect(win5,&Widget5::back51,[=](){
            this->setGeometry(win5->geometry());
            win5->close();
            this->show();
            ui->comboBox2->setCurrentIndex(0);
            ui->comboBox1->setCurrentIndex(0);

        });
    //5-2
    connect(win5,&Widget5::back52,[=](){
            this->setGeometry(win5->geometry());
            win5->close();
            win2->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });

    //5-3
    connect(win5,&Widget5::back53,[=](){
            this->setGeometry(win5->geometry());
            win5->close();
            win3->show();
            ui->comboBox1->setCurrentIndex(0);
            ui->comboBox2->setCurrentIndex(0);

        });


    //开始计算

    connect(ui->btn1,&QPushButton::clicked,[=](){
        //等额本息
        if(ui->rbtn1->isChecked())
            {
        //计算结果显示
        ui->groupBox_2->show();

        //各种框框的值
        //房屋单价的值
        QString fangwudanjia = ui->lineEdit1->text();
        double FANGWUDANJIA = fangwudanjia.toDouble();

        //房屋面积的值
        QString fangwumianji = ui->lineEdit2->text();
        double FANGWUMIANJI = fangwumianji.toDouble();

        //按揭成数的值
        double ANJIECHENGSHU = (8-ui->comboBox3->currentIndex()*0.5)*0.1;

        //按揭年数
        double ANJIENIANSHU = 25-ui->comboBox4->currentIndex();

        //贷款利率
        QString daikuanlilv = ui->lineEdit3->text();
        double DAIKUANLILV = daikuanlilv.toDouble()*0.01/12;

        //等额本息

        //还款月数
        QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',2);
        ui->label_10->setText(huankuanyueshu);
        double HUANKUANYUESHU = huankuanyueshu.toDouble();

        //贷款总额
        QString daikuanzonge = QString::number(FANGWUDANJIA*FANGWUMIANJI*ANJIECHENGSHU,'f',2);
        ui->label_9->setText(daikuanzonge);
        double DAIKUANZONGE = daikuanzonge.toDouble();

        //首付
        QString shoufu = QString::number(FANGWUMIANJI*FANGWUDANJIA-DAIKUANZONGE,'f',2);
        ui->label_7->setText(shoufu);

        //每月月供
        ui->label1_4->setText("每月月供");
        QString meiyueyuegong = QString::number((DAIKUANZONGE*DAIKUANLILV*pow(1+DAIKUANLILV,HUANKUANYUESHU))/(pow(1+DAIKUANLILV,HUANKUANYUESHU)-1),'f',2);
        ui->label_8->setText(meiyueyuegong);
        double MEIYUEYUEGONG = meiyueyuegong.toDouble();


        //还款总额
        QString huankuanzonge = QString::number(MEIYUEYUEGONG*HUANKUANYUESHU,'f',2);
        ui->label_13->setText(huankuanzonge);
        double HUANKUANZONGE = huankuanzonge.toDouble();

        //支付利息
        QString zhifulixi = QString::number(HUANKUANZONGE-DAIKUANZONGE,'f',2);
        ui->label_12->setText(zhifulixi);




        //隐藏每月递减
        ui->label1_9->hide();
        ui->label_15->hide();
        ui->label_16->hide();
        }

        //等额本金
        if(ui->rbtn2->isChecked())
            {
        //计算结果显示
        ui->groupBox_2->show();

        //各种框框的值
        //房屋单价的值
        QString fangwudanjia = ui->lineEdit1->text();
        double FANGWUDANJIA = fangwudanjia.toDouble();

        //房屋面积的值
        QString fangwumianji = ui->lineEdit2->text();
        double FANGWUMIANJI = fangwumianji.toDouble();

        //按揭成数的值
        double ANJIECHENGSHU = (8-ui->comboBox3->currentIndex()*0.5)*0.1;

        //按揭年数
        double ANJIENIANSHU = 25-ui->comboBox4->currentIndex();

        //贷款利率
        QString daikuanlilv = ui->lineEdit3->text();
        double DAIKUANLILV = daikuanlilv.toDouble()*0.01/12;

        //等额本息

        //还款月数
        QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',2);
        ui->label_10->setText(huankuanyueshu);
        double HUANKUANYUESHU = huankuanyueshu.toDouble();

        //贷款总额
        QString daikuanzonge = QString::number(FANGWUDANJIA*FANGWUMIANJI*ANJIECHENGSHU,'f',2);
        ui->label_9->setText(daikuanzonge);
        double DAIKUANZONGE = daikuanzonge.toDouble();

        //首付
        QString shoufu = QString::number(FANGWUMIANJI*FANGWUDANJIA-DAIKUANZONGE,'f',2);
        ui->label_7->setText(shoufu);

        //每月月供本金
        double YUEGONGBENJIN = DAIKUANZONGE/HUANKUANYUESHU;
        //首月月供
        ui->label1_4->setText("首月月供");
        QString shouyueyuegong = QString::number(YUEGONGBENJIN+(DAIKUANZONGE*DAIKUANLILV),'f',2);
        ui->label_8->setText(shouyueyuegong);

        //每月递减
        QString meiyuedijian = QString::number(YUEGONGBENJIN*DAIKUANLILV,'f',2);
         ui->label_15->setText(meiyuedijian);

         //支付利息
         QString zhifulixi = QString::number(DAIKUANZONGE*DAIKUANLILV*(HUANKUANYUESHU+1)/2,'f',2);
         ui->label_12->setText(zhifulixi);
         double ZHIFULIXI = zhifulixi.toDouble();


        //还款总额
        QString huankuanzonge = QString::number(DAIKUANZONGE+ZHIFULIXI,'f',2);
        ui->label_13->setText(huankuanzonge);

        //显示每月递减
        ui->label1_9->show();
        ui->label_15->show();
        ui->label_16->show();
        }
    });
}

//背景event的实现
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}



Widget::~Widget()
{
    delete ui;
}


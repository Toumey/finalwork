#include "widget3.h"
#include "ui_widget3.h"
#include <QIcon>
#include <QPainter>
#include <QLayout>
#include <QPushButton>
#include <QtCore/qmath.h>
#include <QMessageBox>
Widget3::Widget3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget3)
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

    //提示文字
     ui->lineEdit1->setPlaceholderText("请输入商业贷款额");
     ui->lineEdit2->setPlaceholderText("请输入公积金贷款额");
     //限制用户输入
      ui->lineEdit1->setValidator(new QIntValidator(0,999999999,this));
       ui->lineEdit2->setValidator(new QIntValidator(0,999999999,this));

       //将groupbox的边框去除
           ui->groupBox->setStyleSheet("QGroupBox{border:none}");
           ui->groupBox_2->setStyleSheet("QGroupBox{border:none}");

    //贷款类别
    ui->comboBox1->addItem("商业贷款");
    ui->comboBox1->addItem("公积金贷款");
    ui->comboBox1->addItem("组合型贷款");
    ui->comboBox1->setCurrentIndex(2);


    //返回商业贷款3-1 3-2
    connect(ui->comboBox1,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==0)
        {
            emit this->back31();
            ui->comboBox1->setCurrentIndex(2);
        }
        else if(index==1)
        {
            emit this->back32();
            ui->comboBox1->setCurrentIndex(2);
        }
    });


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
          ui->lineEdit3->setText("3.25");
        }
        else if(index==2)
        {
           ui->lineEdit3->setText("3.25");
        }
        else if(index==3)
        {
           ui->lineEdit3->setText("3.25");
        }
        else if(index==4)
        {
           ui->lineEdit3->setText("3.5");
        }
        else if(index==5)
        {
           ui->lineEdit3->setText("3.75");
        }
        else if(index==6)
        {
           ui->lineEdit3->setText("4");
        }
        else if(index==7)
        {
           ui->lineEdit3->setText("4.25");
        }
        else if(index==8)
        {
           ui->lineEdit3->setText("4.5");
        }
        else if(index==9)
        {
           ui->lineEdit3->setText("4.7");
        }

    });

    //公积金利率
    ui->comboBox6->addItem("20年3月20日贷款市场报价率(LPR)");
    ui->comboBox6->addItem("19年9月20日贷款市场报价率(LPR)");
    ui->comboBox6->addItem("15年10月24日基准利率");
    ui->comboBox6->addItem("15年8月26日基准利率");
    ui->comboBox6->addItem("15年6月28日基准利率");
    ui->comboBox6->addItem("15年5月11日基准利率");
    ui->comboBox6->addItem("15年3月1日基准利率");
    ui->comboBox6->addItem("14年11月22日基准利率");
    ui->comboBox6->addItem("12年7月6日基准利率");
    ui->comboBox6->addItem("12年6月8日基准利率");

    connect(ui->comboBox6,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==1)
        {
          ui->lineEdit4->setText("3.25");
        }
        else if(index==2)
        {
           ui->lineEdit4->setText("3.25");
        }
        else if(index==3)
        {
           ui->lineEdit4->setText("3.25");
        }
        else if(index==4)
        {
           ui->lineEdit4->setText("3.5");
        }
        else if(index==5)
        {
           ui->lineEdit4->setText("3.75");
        }
        else if(index==6)
        {
           ui->lineEdit4->setText("4");
        }
        else if(index==7)
        {
           ui->lineEdit4->setText("4.25");
        }
        else if(index==8)
        {
           ui->lineEdit4->setText("4.5");
        }
        else if(index==9)
        {
           ui->lineEdit4->setText("4.7");
        }

    });





    //设置单选按钮 默认值
        ui->rbtn1->setChecked(true);


        //开始计算

        connect(ui->btn1,&QPushButton::clicked,[=](){
            //等额本息
            if(ui->rbtn1->isChecked())
                {
            //计算结果显示
            ui->groupBox_2->show();

            //各种框框的值
            //商业贷款额
            QString shangyedaikuane = ui->lineEdit1->text();
            double SHANGYEDAIKUANE = shangyedaikuane.toDouble()*10000;

            //商贷利率
            QString shangdaililv = ui->lineEdit3->text();
            double SHANGDAILILV = shangdaililv.toDouble()*0.01/12;

            //公积金贷款额
            QString gongjijindaikuane = ui->lineEdit2->text();
            double GONGJIJINDAIKUANE = gongjijindaikuane.toDouble()*10000;

            //公积金贷款利率
            QString gongjijinlilv = ui->lineEdit4->text();
            double GONGJIJINLILV = gongjijinlilv.toDouble()*0.01/12;

            //按揭年数
            double ANJIENIANSHU = 25-ui->comboBox4->currentIndex();



            //还款月数
            QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',0);
            ui->label_10->setText(huankuanyueshu);
            double HUANKUANYUESHU = huankuanyueshu.toDouble();

            //贷款总额
            QString daikuanzonge = QString::number(GONGJIJINDAIKUANE+SHANGYEDAIKUANE,'f',2);
            ui->label_9->setText(daikuanzonge);
            double DAIKUANZONGE = daikuanzonge.toDouble();

            //每月月供
            ui->label1_10->setText("每月月供");
            QString meiyueyuegong = QString::number((SHANGYEDAIKUANE*SHANGDAILILV*pow(1+SHANGDAILILV,HUANKUANYUESHU))/(pow(1+SHANGDAILILV,HUANKUANYUESHU)-1)+(GONGJIJINDAIKUANE*GONGJIJINLILV*pow(1+GONGJIJINLILV,HUANKUANYUESHU))/(pow(1+GONGJIJINLILV,HUANKUANYUESHU)-1),'f',2);
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
            ui->label1_11->hide();
            ui->label_15->hide();
            ui->label_7->hide();
            }

            //等额本金
            if(ui->rbtn2->isChecked())
                {
            //计算结果显示
            ui->groupBox_2->show();

            //各种框框的值
            //商业贷款额
            QString shangyedaikuane = ui->lineEdit1->text();
            double SHANGYEDAIKUANE = shangyedaikuane.toDouble()*10000;

            //商贷利率
            QString shangdaililv = ui->lineEdit3->text();
            double SHANGDAILILV = shangdaililv.toDouble()*0.01/12;

            //公积金贷款额
            QString gongjijindaikuane = ui->lineEdit2->text();
            double GONGJIJINDAIKUANE = gongjijindaikuane.toDouble()*10000;

            //公积金贷款利率
            QString gongjijinlilv = ui->lineEdit4->text();
            double GONGJIJINLILV = gongjijinlilv.toDouble()*0.01/12;

            //按揭年数
            double ANJIENIANSHU = 25-ui->comboBox4->currentIndex();



            //还款月数
            QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',0);
            ui->label_10->setText(huankuanyueshu);
            double HUANKUANYUESHU = huankuanyueshu.toDouble();

            //贷款总额
            QString daikuanzonge = QString::number(GONGJIJINDAIKUANE+SHANGYEDAIKUANE,'f',2);
            ui->label_9->setText(daikuanzonge);
            double DAIKUANZONGE = daikuanzonge.toDouble();

            //每月月供本金
            double SHANGYUEGONGBENJIN = SHANGYEDAIKUANE/HUANKUANYUESHU;
            double GONGYUEGONGBENJIN = GONGJIJINDAIKUANE/HUANKUANYUESHU;
            //首月月供
            ui->label1_10->setText("首月月供");
            QString shouyueyuegong = QString::number(SHANGYUEGONGBENJIN+SHANGYEDAIKUANE*SHANGDAILILV+GONGYUEGONGBENJIN+GONGJIJINDAIKUANE*GONGJIJINLILV,'f',2);
            ui->label_8->setText(shouyueyuegong);
            double SHOUYUEYUEGONG = shouyueyuegong.toDouble();


            //每月递减
            QString meiyuedijian = QString::number(SHANGYUEGONGBENJIN*SHANGDAILILV+GONGYUEGONGBENJIN*GONGJIJINLILV,'f',2);
             ui->label_15->setText(meiyuedijian);

             //支付利息
             QString zhifulixi = QString::number(SHANGYEDAIKUANE*SHANGDAILILV*(HUANKUANYUESHU+1)/2+GONGJIJINDAIKUANE*GONGJIJINLILV*(HUANKUANYUESHU+1)/2,'f',2);
             ui->label_12->setText(zhifulixi);
             double ZHIFULIXI = zhifulixi.toDouble();


            //还款总额
            QString huankuanzonge = QString::number(DAIKUANZONGE+ZHIFULIXI,'f',2);
            ui->label_13->setText(huankuanzonge);

            //显示每月递减
            ui->label1_11->show();
            ui->label_15->show();
            ui->label_7->show();
            }
        });
}


//背景event的实现
void Widget3::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
Widget3::~Widget3()
{
    delete ui;
}

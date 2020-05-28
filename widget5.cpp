#include "widget5.h"
#include "ui_widget5.h"
#include <QIcon>
#include <QPainter>
#include <QLayout>
#include <QPushButton>
#include <QtCore/qmath.h>
#include <QMessageBox>
Widget5::Widget5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget5)
{
    ui->setupUi(this);

    //设置窗口部分显示
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    //隐藏第二部分
    ui->groupBox_2->hide();

    //设置图标
    setWindowIcon(QIcon(":/image/houseicon.png"));

    // 设置标题
    setWindowTitle("房贷计算器");
    //设置清空重置按钮的功能
        connect(ui->btn2,&QPushButton::clicked,[=](){
            int a = QMessageBox::question(this,"确认操作","是否清空重置？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
            if(a==QMessageBox::Yes)
            {
            this->ui->lineEdit1->clear();
            ui->groupBox_2->hide();
            }
        });

    //提示信息
    ui->lineEdit1->setPlaceholderText("请输入贷款总额");
    //限制用户输入
     ui->lineEdit1->setValidator(new QIntValidator(0,999999999,this));
     //将groupbox的边框去除
         ui->groupBox->setStyleSheet("QGroupBox{border:none}");
         ui->groupBox_2->setStyleSheet("QGroupBox{border:none}");

    //贷款类别
    ui->comboBox1->addItem("商业贷款");
    ui->comboBox1->addItem("公积金贷款");
    ui->comboBox1->addItem("组合型贷款");
    ui->comboBox1->setCurrentIndex(1);

    //    商贷计算方法的切换
        ui->comboBox2->addItem("根据面积、单价计算");
        ui->comboBox2->addItem("根据贷款总额计算");
        ui->comboBox2->setCurrentIndex(1);
        //5-1
        connect(ui->comboBox1,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
            if(index==0)
            {
                emit this->back51();
                ui->comboBox1->setCurrentIndex(1);
                ui->comboBox2->setCurrentIndex(1);
            }
        });

    //5-3
        connect(ui->comboBox1,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
            if(index==2)
               {
                   emit this->back53();
                   ui->comboBox1->setCurrentIndex(1);
                   ui->comboBox2->setCurrentIndex(1);
               }
        });



        //5-2
            connect(ui->comboBox2,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
            if(index==0)
            {
                emit this->back52();
                ui->comboBox1->setCurrentIndex(1);
                ui->comboBox2->setCurrentIndex(1);
            }

        });

        //按揭年数
        ui->comboBox3->addItem("25年（300期）");
        ui->comboBox3->addItem("24年（288期）");
        ui->comboBox3->addItem("23年（276期）");
        ui->comboBox3->addItem("22年（264期）");
        ui->comboBox3->addItem("21年（252期）");
        ui->comboBox3->addItem("20年（240期）");
        ui->comboBox3->addItem("19年（228期）");
        ui->comboBox3->addItem("18年（216期）");
        ui->comboBox3->addItem("17年（204期）");
        ui->comboBox3->addItem("16年（192期）");
        ui->comboBox3->addItem("15年（180期）");
        ui->comboBox3->addItem("14年（168期）");
        ui->comboBox3->addItem("13年（156期）");
        ui->comboBox3->addItem("12年（144期）");
        ui->comboBox3->addItem("11年（132期）");
        ui->comboBox3->addItem("10年（120期）");
        ui->comboBox3->addItem("9年（108期）");
        ui->comboBox3->addItem("8年（96期）");
        ui->comboBox3->addItem("7年（84期）");
        ui->comboBox3->addItem("6年（72期）");
        ui->comboBox3->addItem("5年（60期）");
        ui->comboBox3->addItem("4年（48期）");
        ui->comboBox3->addItem("3年（36期）");
        ui->comboBox3->addItem("2年（24期）");
        ui->comboBox3->addItem("1年（12期）");

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

        //开始计算

        connect(ui->btn1,&QPushButton::clicked,[=](){
            //等额本息
            if(ui->rbtn1->isChecked())
                {
            //计算结果显示
            ui->groupBox_2->show();

            //各种框框的值
            //贷款总额
            QString daikuanzonge = ui->lineEdit1->text();
            double DAIKUANZONGE = daikuanzonge.toDouble()*10000;
            QString dkze = QString::number(DAIKUANZONGE,'f',2);
            ui->label_9->setText(dkze);

            //贷款利率
            QString daikuanlilv = ui->lineEdit3->text();
            double DAIKUANLILV = daikuanlilv.toDouble()*0.01/12;

            //按揭年数
            double ANJIENIANSHU = 25-ui->comboBox3->currentIndex();

            //还款月数
            QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',0);
            ui->label_10->setText(huankuanyueshu);
            double HUANKUANYUESHU = huankuanyueshu.toDouble();

            //每月月供
            ui->label1_10->setText("每月月供");
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
            QString daikuanzonge = ui->lineEdit1->text();
            double DAIKUANZONGE = daikuanzonge.toDouble()*10000;
            QString dkze = QString::number(DAIKUANZONGE,'f',2);
            ui->label_9->setText(dkze);

            //贷款利率
            QString daikuanlilv = ui->lineEdit3->text();
            double DAIKUANLILV = daikuanlilv.toDouble()*0.01/12;

            //按揭年数
            double ANJIENIANSHU = 25-ui->comboBox3->currentIndex();

            //还款月数
            QString huankuanyueshu = QString::number(ANJIENIANSHU*12,'f',0);
            ui->label_10->setText(huankuanyueshu);
            double HUANKUANYUESHU = huankuanyueshu.toDouble();

            //每月月供本金
            double YUEGONGBENJIN = DAIKUANZONGE/HUANKUANYUESHU;

            //首月月供
            ui->label1_10->setText("首月月供");
            QString shouyueyuegong = QString::number(YUEGONGBENJIN+DAIKUANZONGE*DAIKUANLILV,'f',0);
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
            ui->label1_11->show();
            ui->label_15->show();
            ui->label_7->show();
            }
        });
}


//背景event的实现
void Widget5::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
Widget5::~Widget5()
{
    delete ui;
}

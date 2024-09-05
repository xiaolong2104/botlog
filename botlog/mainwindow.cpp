/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2022 Emanuel Eichhammer                            **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: https://www.qcustomplot.com/                         **
**             Date: 06.11.22                                             **
**          Version: 2.1.1                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>


#define RECORDLOGTIME 100
#define PENWIDTH 2

enum PLOT
{
    vel_teb = 0,
    omg_teb,
    vel_teb_fb,
    omg_teb_fb,
    leftmotorspd,
    rightmotorspd,
    leftmotorspd_fb,
    rightmotorspd_fb,
    omg_imu,
    omg_coder,
    leftmotorstate,
    rightmotorstate,
    leftmotortemp,
    rightmotortemp,
    leftdrivertemp,
    rightdrivertemp,
    x,
    y,
    heading,
    motorpower,
    estop,
    crashstop,
    qiyaval,
    crashval,
};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  //getData();
  //setupPlotMy();
  
  // configure scroll bars:
  // Since scroll bars only support integer values, we'll set a high default range of -500..500 and
  // divide scroll bar position values by 100 to provide a scroll range -5..5 in floating point
  // axis coordinates. if you want to dynamically grow the range accessible with the scroll bar,
  // just increase the minimum/maximum values of the scroll bars as needed.
  ui->horizontalScrollBar->setRange(-500, 500);
  ui->verticalScrollBar->setRange(-500, 500);
  
  // create connection between axes and scroll bars:
  connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
  connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
  connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
  connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
  
  readLineCnt = 0;

  // initialize axis range (and scroll bar positions via signals we just connected):
  //ui->plot->xAxis->setRange(0, 6, Qt::AlignCenter);
  ui->plot->xAxis->setRange(0, 6, Qt::AlignLeft);
  ui->plot->yAxis->setRange(0, 10, Qt::AlignCenter);

  this->setWindowTitle("Botlog Analyzer v1.1");

  connect(ui->plot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));


  //定义日期
  /*QString dateContent = "2023-03-16 17:27:00";// "2016-02-19 22:11:33" ;
  QDateTime time;

  time = QDateTime::fromString(dateContent,"yyyy-MM-dd hh:mm:ss");
  qDebug()<<time.toTime_t();*/

  textTicker = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);

}

MainWindow::~MainWindow()
{
  delete ui;
}


/*----------------
1        black,
2        darkRed,
3        darkGreen,
4        darkBlue,
5        red,
6        green,
7        blue,
8        cyan,
9        magenta,
10        yellow,
11        darkRed,
12        darkGreen,
13        darkBlue,
14        darkCyan,
15        darkMagenta,
16        darkYellow,

17        black,
18        darkGray,
19        gray,
20        lightGray,
21        red,
22        green,
23        blue,
24        cyan,

------------*/
void MainWindow::setupPlotMy()
{
    // The following plot setup is mostly taken from the plot demos:
    //1 vel_teb

    //QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->clear();
    textTicker->addTicks(x_time_,x_time_str_);

    ui->plot->addGraph();
    QPen mypen;
    mypen.setColor(Qt::black);
    mypen.setWidth(PENWIDTH);
    ui->plot->graph()->setPen(mypen);
    //ui->plot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->plot->graph(PLOT::vel_teb)->setData(x_time_, vel_teb);
    ui->plot->graph(PLOT::vel_teb)->setVisible(false);


    //2 omg_teb
    ui->plot->addGraph();
    //mypen.setColor(Qt::darkRed);
    //mypen.setWidth(PENWIDTH);
    //ui->plot->graph()->setPen(mypen);
    ui->plot->graph()->setPen(QPen(Qt::darkRed));
    ui->plot->graph(PLOT::omg_teb)->setData(x_time_, omg_teb);
    ui->plot->graph(PLOT::omg_teb)->setVisible(false);

    //3 vel_teb_fb
    ui->plot->addGraph();
    //mypen.setColor(Qt::darkGreen);
    //mypen.setWidth(PENWIDTH);
    //ui->plot->graph()->setPen(mypen);
    ui->plot->graph()->setPen(QPen(Qt::darkGreen));
    ui->plot->graph(PLOT::vel_teb_fb)->setData(x_time_, vel_teb_fb);
    ui->plot->graph(PLOT::vel_teb_fb)->setVisible(false);

    //4 omg_teb_fb
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkBlue));
    ui->plot->graph(PLOT::omg_teb_fb)->setData(x_time_, omg_teb_fb);
    ui->plot->graph(PLOT::omg_teb_fb)->setVisible(false);


    //5 leftmotorspd
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::red));
    ui->plot->graph(PLOT::leftmotorspd)->setData(x_time_, leftmotorspd);
    ui->plot->graph(PLOT::leftmotorspd)->setVisible(false);


    //6 rightmotorspd
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::green));
    ui->plot->graph(PLOT::rightmotorspd)->setData(x_time_, rightmotorspd);
    ui->plot->graph(PLOT::rightmotorspd)->setVisible(false);



    //7 leftmotorspd_fb
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::blue));
    ui->plot->graph(PLOT::leftmotorspd_fb)->setData(x_time_, leftmotorspd_fb);
    ui->plot->graph(PLOT::leftmotorspd_fb)->setVisible(false);


    //8 rightmotorspd_fb
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::cyan));
    ui->plot->graph(PLOT::rightmotorspd_fb)->setData(x_time_, rightmotorspd_fb);
    ui->plot->graph(PLOT::rightmotorspd_fb)->setVisible(false);


    //9 omg_imu
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::magenta));
    ui->plot->graph(PLOT::omg_imu)->setData(x_time_, omg_imu);
    ui->plot->graph(PLOT::omg_imu)->setVisible(false);


    //10 omg_imu
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::yellow));
    ui->plot->graph(PLOT::omg_coder)->setData(x_time_, omg_coder);
    ui->plot->graph(PLOT::omg_coder)->setVisible(false);



    //11 leftmotorstate
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkRed));
    ui->plot->graph(PLOT::leftmotorstate)->setData(x_time_, leftmotorstate);
    ui->plot->graph(PLOT::leftmotorstate)->setVisible(false);


    //12 rightmotorstate
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkGreen));
    ui->plot->graph(PLOT::rightmotorstate)->setData(x_time_, rightmotorstate);
    ui->plot->graph(PLOT::rightmotorstate)->setVisible(false);


    //13 leftmotortemp
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkBlue));
    ui->plot->graph(PLOT::leftmotortemp)->setData(x_time_, leftmotortemp);
    ui->plot->graph(PLOT::leftmotortemp)->setVisible(false);

    //14 rightmotortemp
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkCyan));
    ui->plot->graph(PLOT::rightmotortemp)->setData(x_time_, rightmotortemp);
    ui->plot->graph(PLOT::rightmotortemp)->setVisible(false);


    //15 leftdrivertemp
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkMagenta));
    ui->plot->graph(PLOT::leftdrivertemp)->setData(x_time_, leftdrivertemp);
    ui->plot->graph(PLOT::leftdrivertemp)->setVisible(false);


    //16 rightrivertemp
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkYellow));
    ui->plot->graph(PLOT::rightdrivertemp)->setData(x_time_, rightdrivertemp);
    ui->plot->graph(PLOT::rightdrivertemp)->setVisible(false);

    //17 x
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::black));
    ui->plot->graph(PLOT::x)->setData(x_time_, x);
    ui->plot->graph(PLOT::x)->setVisible(false);


    //18 y
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::darkGray));
    ui->plot->graph(PLOT::y)->setData(x_time_, y);
    ui->plot->graph(PLOT::y)->setVisible(false);


    //19 heading
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::gray));
    ui->plot->graph(PLOT::heading)->setData(x_time_, heading);
    ui->plot->graph(PLOT::heading)->setVisible(false);

    //20 motorpower
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::lightGray));
    ui->plot->graph(PLOT::motorpower)->setData(x_time_, motorpower);
    ui->plot->graph(PLOT::motorpower)->setVisible(false);


    //21 estop
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::red));
    ui->plot->graph(PLOT::estop)->setData(x_time_, estop);
    ui->plot->graph(PLOT::estop)->setVisible(false);


    //22 crashstop
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::green));
    ui->plot->graph(PLOT::crashstop)->setData(x_time_, crashstop);
    ui->plot->graph(PLOT::crashstop)->setVisible(false);



    //23 qiyaval
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::blue));
    ui->plot->graph(PLOT::qiyaval)->setData(x_time_, qiyaval);
    ui->plot->graph(PLOT::qiyaval)->setVisible(false);



    //24 crashval
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::cyan));
    ui->plot->graph(PLOT::crashval)->setData(x_time_, crashval);
    ui->plot->graph(PLOT::crashval)->setVisible(false);








    ui->plot->xAxis->setTicker(textTicker);
    //ui->plot->xAxis->setTickLength(0,4);
    ui->plot->xAxis->setTickLabelRotation(30);
    //ui->plot->xAxis->setTickLabels(false);


    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->plot->replot();


    //解析数据的行数x100ms 一次的统计频率！
    qint64 xRangeMax = readLineCnt*RECORDLOGTIME;
    qDebug()<<" xRangeMax "<<xRangeMax<<"  readLineCnt "<<readLineCnt;
    //ui->plot->xAxis->setRange(0, 6, Qt::AlignLeft);
    ui->plot->xAxis->setRange(0, xRangeMax, Qt::AlignLeft);

    ui->spinBox->setValue(100);
    ui->plot->yAxis->setRange(0, 100, Qt::AlignCenter);
    ui->plot->replot();




}


/*
void MainWindow::setupPlot()
{
  // The following plot setup is mostly taken from the plot demos:
  ui->plot->addGraph();
  ui->plot->graph()->setPen(QPen(Qt::blue));
  ui->plot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
  ui->plot->addGraph();

  ui->plot->graph()->setPen(QPen(Qt::red));
  QVector<double> x(500), y0(500), y1(500);
  for (int i=0; i<500; ++i)
  {
    x[i] = (i/499.0-0.5)*10;
    y0[i] = qExp(-x[i]*x[i]*0.25)*qSin(x[i]*5)*5;
    y1[i] = qExp(-x[i]*x[i]*0.25)*5;
  }



  ui->plot->graph(0)->setData(x, y0);
  ui->plot->graph(1)->setData(x, y1);

  ui->plot->addGraph();
  for (int i=0; i<500; ++i)
  {
    x[i] = (i/499.0-0.5)*10;
    y0[i] = qExp(-x[i]*x[i]*0.25)*qSin(x[i]*5)*6;

  }

  ui->plot->graph(2)->setData(x, y0);
  ui->plot->axisRect()->setupFullAxesBox(true);
  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
*/

void MainWindow::horzScrollBarChanged(int value)
{
  if (qAbs(ui->plot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->plot->xAxis->setRange(value/100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
    ui->plot->replot();
  }
}

void MainWindow::vertScrollBarChanged(int value)
{
  if (qAbs(ui->plot->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->plot->yAxis->setRange(-value/100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
    ui->plot->replot();
  }
}

void MainWindow::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::yAxisChanged(QCPRange range)
{
  ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
  ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}


void MainWindow::getData()
{
    if(endTime.isNull())
        endTime=QDateTime::currentDateTime();

    //QFile file("D:\\Motorlog.log");
    QFile file(openfilepath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {

        //qDebug()<<" get data "<<file.readAll();
        double indextime = 0;
        while (!file.atEnd())
        //while (true)
        {

            QByteArray line = file.readLine();
            //qDebug()<<line;
            QString linestr = line;
            QStringList strlist = linestr.split(",");
            QString temp_time;
            //qDebug()<<strlist;
            if( strlist.size() >=25  )
            {                 
                QString temp = strlist.at(0);
                //x_time.append(temp);
                QStringList dateList = temp.split(".");
                if(dateList.size()>=2)
                temp_time = dateList.at(0);
                QDateTime logtime = QDateTime::fromString(temp_time,"yyyy-MM-dd hh:mm:ss");
                //qDebug()<<" ok "<<logtime<<" starttime "<<startTime<<" endtime "<<endTime;
                if( logtime >=startTime && logtime <=endTime )
                {
                    //读到复合时间格式的数据才增加计数！
                    readLineCnt++;
                }
                else
                    continue;

                indextime += RECORDLOGTIME; //100,200,300ms
                x_time_.append(indextime);
                QStringList temp_timeList = temp_time.split(" ");
                if(temp_timeList.size()>=2)
                {
                    if( (int)indextime % 1000 == 0)     //每隔一秒绘制出曲线图！
                        x_time_str_.append(temp_timeList.at(1));
                    else
                        x_time_str_.append("");     //100ms 一次的x轴先设置为空，不显示出来！！！
                }


                temp = strlist.at(1);
                QStringList templisr = temp.split(":");
                if( templisr.size() >=2 )
                   vel_teb.append(templisr.at(1).toDouble());

                temp = strlist.at(2);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   omg_teb.append(templisr.at(1).toDouble());


                temp = strlist.at(3);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   vel_teb_fb.append(templisr.at(1).toDouble());

                temp = strlist.at(4);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   omg_teb_fb.append(templisr.at(1).toDouble());

                temp = strlist.at(5);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   leftmotorspd.append(templisr.at(1).toDouble());

                temp = strlist.at(6);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   rightmotorspd.append(templisr.at(1).toDouble());

                temp = strlist.at(7);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   leftmotorspd_fb.append(templisr.at(1).toDouble());

                temp = strlist.at(8);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   rightmotorspd_fb.append(templisr.at(1).toDouble());


                temp = strlist.at(9);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   omg_imu.append(templisr.at(1).toDouble());

                temp = strlist.at(10);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   omg_coder.append(templisr.at(1).toDouble());


                temp = strlist.at(11);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   leftmotorstate.append(templisr.at(1).toDouble());

                temp = strlist.at(12);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   rightmotorstate.append(templisr.at(1).toDouble());

                temp = strlist.at(13);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   leftmotortemp.append(templisr.at(1).toDouble());

                temp = strlist.at(14);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   rightmotortemp.append(templisr.at(1).toDouble());

                temp = strlist.at(15);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   leftdrivertemp.append(templisr.at(1).toDouble());

                temp = strlist.at(16);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   rightdrivertemp.append(templisr.at(1).toDouble());


                temp = strlist.at(17);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   x.append(templisr.at(1).toDouble());

                temp = strlist.at(18);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   y.append(templisr.at(1).toDouble());


                temp = strlist.at(19);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   heading.append(templisr.at(1).toDouble());

                temp = strlist.at(20);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                {
                    //motorpower.append(templisr.at(1).toDouble());
                    if( templisr.at(1).contains( "True" ) )
                    {
                        motorpower.append(1);
                    }
                    else if( templisr.at(1).contains( "False" ) )
                    {
                        motorpower.append(0);
                    }

                }


                temp = strlist.at(21);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                {
                    //estop.append(templisr.at(1).toInt());
                    if( templisr.at(1).contains( "True" ) )
                    {
                        estop.append(1);
                    }
                    else if( templisr.at(1).contains( "False" ) )
                    {
                        estop.append(0);
                    }
                }

                temp = strlist.at(22);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                {
                    //crashstop.append(templisr.at(1).toInt());
                    if( templisr.at(1).contains( "True" ) )
                    {
                        crashstop.append(1);
                    }
                    else if( templisr.at(1).contains( "False" ) )
                    {
                        crashstop.append(0);
                    }
                }

                temp = strlist.at(23);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   qiyaval.append(templisr.at(1).toInt());

                temp = strlist.at(24);
                templisr = temp.split(":");
                if( templisr.size() >=2 )
                   crashval.append(templisr.at(1).toDouble());




            }



        }


        file.close();

    }
    else
    {
        qDebug()<<"read err";
    }
}






void MainWindow::on_openfile_clicked()
{
    openfilepath = QFileDialog::getOpenFileName(this,"open file dialog","/",
            "log files(*.log)");
    //fileLineEdit->setText(s);
    qDebug()<<openfilepath;

    reSetData();
    getData();
    setupPlotMy();

}


void MainWindow::on_vel_teb_clicked(bool checked)
{
    qDebug()<<" checked "<<checked;
    if(ui->plot->graph(PLOT::vel_teb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::vel_teb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::vel_teb)->setVisible(false);
    }

    ui->plot->replot();


}

void MainWindow::on_omg_teb_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::omg_teb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::omg_teb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::omg_teb)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_vel_teb_fb_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::vel_teb_fb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::vel_teb_fb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::vel_teb_fb)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_omg_teb_fb_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::omg_teb_fb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::omg_teb_fb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::omg_teb_fb)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_leftmotorspd_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::leftmotorspd) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::leftmotorspd)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::leftmotorspd)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_rightmotorspd_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::rightmotorspd) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::rightmotorspd)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::rightmotorspd)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_leftmotorspd_fb_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::leftmotorspd_fb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::leftmotorspd_fb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::leftmotorspd_fb)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    ;//qDebug()<<" action "<<action<<" readLineCnt"<<readLineCnt;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    qDebug()<<" position "<<position<<" readLineCnt"<<readLineCnt;
    //0-99

}

void MainWindow::on_spinBox_editingFinished()
{
    qDebug()<<" on_spinBox_editingFinished  ";
    ui->plot->yAxis->setRange(0, ui->spinBox->value(), Qt::AlignCenter);

    ui->plot->replot();
    //ui->plot->update();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug()<<" on_spinBox_valueChanged "<<arg1;
    ui->plot->yAxis->setRange(0, ui->spinBox->value(), Qt::AlignCenter);

    ui->plot->replot();
    //ui->plot->update();
}

void MainWindow::reSetData()
{
    x_time_str_.clear();
    x_time_.clear();
    vel_teb.clear();
    omg_teb.clear();
    vel_teb_fb.clear();
    omg_teb_fb.clear();
    leftmotorspd.clear();
    rightmotorspd.clear();
    leftmotorspd_fb.clear();
    rightmotorspd_fb.clear();
    omg_imu.clear();
    omg_coder.clear();
    leftmotorstate.clear();
    rightmotorstate.clear();
    leftmotortemp.clear();
    rightmotortemp.clear();
    leftdrivertemp.clear();
    rightdrivertemp.clear();
    x.clear();
    y.clear();
    heading.clear();
    motorpower.clear();
    estop.clear();
    crashstop.clear();
    qiyaval.clear();
    crashval.clear();
    readLineCnt = 0;

    ui->vel_teb->setChecked(false);
    ui->omg_teb->setChecked(false);
    ui->vel_teb_fb->setChecked(false);
    ui->omg_teb_fb->setChecked(false);
    ui->leftmotorspd->setChecked(false);
    ui->rightmotorspd->setChecked(false);
    ui->leftmotorspd_fb->setChecked(false);
    ui->rightmotorspd_fb->setChecked(false);
    ui->omg_imu->setChecked(false);
    ui->omg_coder->setChecked(false);
    ui->leftmotorstate->setChecked(false);
    ui->rightmotorstate->setChecked(false);
    ui->leftdrivertemp->setChecked(false);
    ui->rightmotortemp->setChecked(false);
    ui->leftdrivertemp->setChecked(false);
    ui->rightdrivertemp->setChecked(false);
    ui->robotx->setChecked(false);
    ui->roboty->setChecked(false);
    ui->heading->setChecked(false);
    ui->motorpower->setChecked(false);
    ui->estop->setChecked(false);
    ui->crashstop->setChecked(false);
    ui->qiyaval->setChecked(false);
    ui->crashval->setChecked(false);

    //startTime=QDateTime();
    //endTime=QDateTime();

}

void MainWindow::on_rightmotorspd_fb_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::rightmotorspd_fb) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::rightmotorspd_fb)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::rightmotorspd_fb)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_omg_imu_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::omg_imu) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::omg_imu)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::omg_imu)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_omg_coder_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::omg_coder) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::omg_coder)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::omg_coder)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_leftmotorstate_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::leftmotorstate) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::leftmotorstate)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::leftmotorstate)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_rightmotorstate_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::rightmotorstate) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::rightmotorstate)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::rightmotorstate)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_leftmotortemp_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::leftmotortemp) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::leftmotortemp)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::leftmotortemp)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_rightmotortemp_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::rightmotortemp) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::rightmotortemp)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::rightmotortemp)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_qiyaval_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::qiyaval) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::qiyaval)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::qiyaval)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_robotx_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::x) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::x)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::x)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_roboty_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::y) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::y)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::y)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_heading_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::heading) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::heading)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::heading)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_leftdrivertemp_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::leftdrivertemp) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::leftdrivertemp)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::leftdrivertemp)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_rightdrivertemp_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::rightdrivertemp) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::rightdrivertemp)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::rightdrivertemp)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_crashstop_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::crashstop) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::crashstop)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::crashstop)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_estop_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::estop) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::estop)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::estop)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_motorpower_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::motorpower) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::motorpower)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::motorpower)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_crashval_clicked(bool checked)
{
    if(ui->plot->graph(PLOT::crashval) == nullptr )
    {
        return;
    }

    if( checked == true )
    {

        ui->plot->graph(PLOT::crashval)->setVisible(true);
    }
    else
    {

        ui->plot->graph(PLOT::crashval)->setVisible(false);
    }

    ui->plot->replot();
}

void MainWindow::on_dateEditstart_dateChanged(const QDate &date)
{
    //qDebug()<<"on_dateEditstart_dateChanged "<<date.toString();
}

void MainWindow::on_dateTimeEditStart_dateChanged(const QDate &date)
{
    ;//qDebug()<<"on_dateEditstart_dateChanged "<<date.toString();
}

void MainWindow::on_dateTimeEditStart_dateTimeChanged(const QDateTime &dateTime)
{
    /*qDebug()<<"on_dateTimeEditStart_dateTimeChanged "<<dateTime.toTime_t();
    QString dateContent = "2023-03-16 17:27:00";// "2016-02-19 22:11:33" ;
    QDateTime time;

    time = QDateTime::fromString(dateContent,"yyyy-MM-dd hh:mm:ss");
    qDebug()<<time;


    if(time < dateTime)
    {
        qDebug()<<"time < dateTime";
    }
    else
    {
        qDebug()<<"time > dateTime";
    }*/

    startTime = dateTime;
}

void MainWindow::on_dateTimeEditEnd_dateTimeChanged(const QDateTime &dateTime)
{
    endTime = dateTime;
}

void MainWindow::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
  // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
  // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
  double dataValue = plottable->interface1D()->dataMainKey(dataIndex); //dataMainValue(dataIndex);
  QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
  //ui->statusBar->showMessage(message, 2500);
  qDebug()<<" msg "<<message;

}

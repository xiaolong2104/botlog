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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  //void setupPlot();
  void setupPlotMy();
  void getData();
  
private slots:
  void horzScrollBarChanged(int value);
  void vertScrollBarChanged(int value);
  void xAxisChanged(QCPRange range);
  void yAxisChanged(QCPRange range);
  
  void on_openfile_clicked();

  void on_vel_teb_clicked(bool checked);

  void on_omg_teb_clicked(bool checked);

  void on_vel_teb_fb_clicked(bool checked);

  void on_omg_teb_fb_clicked(bool checked);

  void on_leftmotorspd_clicked(bool checked);

  void on_rightmotorspd_clicked(bool checked);

  void on_leftmotorspd_fb_clicked(bool checked);

  void on_horizontalSlider_actionTriggered(int action);

  void on_horizontalSlider_sliderMoved(int position);

  void on_spinBox_editingFinished();

  void on_spinBox_valueChanged(int arg1);

  void reSetData();

  void on_rightmotorspd_fb_clicked(bool checked);

  void on_omg_imu_clicked(bool checked);

  void on_omg_coder_clicked(bool checked);

  void on_leftmotorstate_clicked(bool checked);

  void on_rightmotorstate_clicked(bool checked);

  void on_leftmotortemp_clicked(bool checked);

  void on_rightmotortemp_clicked(bool checked);

  void on_qiyaval_clicked(bool checked);

  void on_robotx_clicked(bool checked);

  void on_roboty_clicked(bool checked);

  void on_heading_clicked(bool checked);

  void on_leftdrivertemp_clicked(bool checked);

  void on_rightdrivertemp_clicked(bool checked);

  void on_crashstop_clicked(bool checked);

  void on_estop_clicked(bool checked);

  void on_motorpower_clicked(bool checked);

  void on_crashval_clicked(bool checked);

  void on_dateEditstart_dateChanged(const QDate &date);

  void on_dateTimeEditStart_dateChanged(const QDate &date);

  void on_dateTimeEditStart_dateTimeChanged(const QDateTime &dateTime);

  void on_dateTimeEditEnd_dateTimeChanged(const QDateTime &dateTime);

  void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

private:
  Ui::MainWindow *ui;

  QVector<QString> x_time_str_;
  QVector<double> x_time_;

  QVector<double> vel_teb;
  QVector<double> omg_teb;
  QVector<double> vel_teb_fb;
  QVector<double> omg_teb_fb;
  QVector<double> leftmotorspd;
  QVector<double> rightmotorspd;
  QVector<double> leftmotorspd_fb;
  QVector<double> rightmotorspd_fb;
  QVector<double> omg_imu;
  QVector<double> omg_coder;
  QVector<double> leftmotorstate;
  QVector<double> rightmotorstate;
  QVector<double> leftmotortemp;
  QVector<double> rightmotortemp;
  QVector<double> leftdrivertemp;
  QVector<double> rightdrivertemp;
  QVector<double> x;
  QVector<double> y;
  QVector<double> heading;
  /*QVector<bool> motorpower;
  QVector<bool> estop;
  QVector<bool> crashstop;*/
  QVector<double> motorpower;
  QVector<double> estop;
  QVector<double> crashstop;
  QVector<double> qiyaval;
  QVector<double> crashval;

  qint64 readLineCnt;

  QString openfilepath;

  QDateTime startTime;
  QDateTime endTime;

  QSharedPointer<QCPAxisTickerText> textTicker;

};

#endif // MAINWINDOW_H

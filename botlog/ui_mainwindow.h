/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInsert_Plot;
    QAction *actionSave_Document;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QCustomPlot *plot;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *openfile;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *vel_teb;
    QCheckBox *omg_teb;
    QCheckBox *vel_teb_fb;
    QCheckBox *omg_teb_fb;
    QCheckBox *leftmotorspd;
    QCheckBox *rightmotorspd;
    QCheckBox *leftmotorspd_fb;
    QCheckBox *rightmotorspd_fb;
    QCheckBox *omg_imu;
    QCheckBox *omg_coder;
    QCheckBox *leftmotorstate;
    QSplitter *splitter;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEditStart;
    QSplitter *splitter_2;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEditEnd;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *rightmotorstate;
    QCheckBox *leftmotortemp;
    QCheckBox *rightmotortemp;
    QCheckBox *qiyaval;
    QCheckBox *robotx;
    QCheckBox *roboty;
    QCheckBox *heading;
    QCheckBox *leftdrivertemp;
    QCheckBox *rightdrivertemp;
    QCheckBox *crashstop;
    QCheckBox *estop;
    QCheckBox *motorpower;
    QCheckBox *crashval;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QSpinBox *spinBox;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(968, 640);
        actionInsert_Plot = new QAction(MainWindow);
        actionInsert_Plot->setObjectName(QStringLiteral("actionInsert_Plot"));
        actionSave_Document = new QAction(MainWindow);
        actionSave_Document->setObjectName(QStringLiteral("actionSave_Document"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(plot, 0, 0, 1, 1);

        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalScrollBar->sizePolicy().hasHeightForWidth());
        verticalScrollBar->setSizePolicy(sizePolicy1);
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout_4->addWidget(verticalScrollBar, 0, 1, 1, 1);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalScrollBar, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 1);

        openfile = new QPushButton(centralWidget);
        openfile->setObjectName(QStringLiteral("openfile"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openfile->sizePolicy().hasHeightForWidth());
        openfile->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(openfile, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        vel_teb = new QCheckBox(centralWidget);
        vel_teb->setObjectName(QStringLiteral("vel_teb"));

        horizontalLayout_9->addWidget(vel_teb);

        omg_teb = new QCheckBox(centralWidget);
        omg_teb->setObjectName(QStringLiteral("omg_teb"));

        horizontalLayout_9->addWidget(omg_teb);

        vel_teb_fb = new QCheckBox(centralWidget);
        vel_teb_fb->setObjectName(QStringLiteral("vel_teb_fb"));

        horizontalLayout_9->addWidget(vel_teb_fb);

        omg_teb_fb = new QCheckBox(centralWidget);
        omg_teb_fb->setObjectName(QStringLiteral("omg_teb_fb"));

        horizontalLayout_9->addWidget(omg_teb_fb);

        leftmotorspd = new QCheckBox(centralWidget);
        leftmotorspd->setObjectName(QStringLiteral("leftmotorspd"));

        horizontalLayout_9->addWidget(leftmotorspd);

        rightmotorspd = new QCheckBox(centralWidget);
        rightmotorspd->setObjectName(QStringLiteral("rightmotorspd"));

        horizontalLayout_9->addWidget(rightmotorspd);

        leftmotorspd_fb = new QCheckBox(centralWidget);
        leftmotorspd_fb->setObjectName(QStringLiteral("leftmotorspd_fb"));

        horizontalLayout_9->addWidget(leftmotorspd_fb);

        rightmotorspd_fb = new QCheckBox(centralWidget);
        rightmotorspd_fb->setObjectName(QStringLiteral("rightmotorspd_fb"));

        horizontalLayout_9->addWidget(rightmotorspd_fb);

        omg_imu = new QCheckBox(centralWidget);
        omg_imu->setObjectName(QStringLiteral("omg_imu"));

        horizontalLayout_9->addWidget(omg_imu);

        omg_coder = new QCheckBox(centralWidget);
        omg_coder->setObjectName(QStringLiteral("omg_coder"));

        horizontalLayout_9->addWidget(omg_coder);

        leftmotorstate = new QCheckBox(centralWidget);
        leftmotorstate->setObjectName(QStringLiteral("leftmotorstate"));

        horizontalLayout_9->addWidget(leftmotorstate);


        gridLayout->addLayout(horizontalLayout_9, 0, 1, 1, 4);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        dateTimeEditStart = new QDateTimeEdit(splitter);
        dateTimeEditStart->setObjectName(QStringLiteral("dateTimeEditStart"));
        dateTimeEditStart->setDateTime(QDateTime(QDate(2023, 3, 1), QTime(0, 0, 0)));
        dateTimeEditStart->setTime(QTime(0, 0, 0));
        splitter->addWidget(dateTimeEditStart);

        gridLayout->addWidget(splitter, 2, 2, 1, 1);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_2->addWidget(label_3);
        dateTimeEditEnd = new QDateTimeEdit(splitter_2);
        dateTimeEditEnd->setObjectName(QStringLiteral("dateTimeEditEnd"));
        dateTimeEditEnd->setDateTime(QDateTime(QDate(2023, 4, 1), QTime(0, 0, 0)));
        splitter_2->addWidget(dateTimeEditEnd);

        gridLayout->addWidget(splitter_2, 2, 4, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        rightmotorstate = new QCheckBox(centralWidget);
        rightmotorstate->setObjectName(QStringLiteral("rightmotorstate"));

        horizontalLayout_10->addWidget(rightmotorstate);

        leftmotortemp = new QCheckBox(centralWidget);
        leftmotortemp->setObjectName(QStringLiteral("leftmotortemp"));

        horizontalLayout_10->addWidget(leftmotortemp);

        rightmotortemp = new QCheckBox(centralWidget);
        rightmotortemp->setObjectName(QStringLiteral("rightmotortemp"));

        horizontalLayout_10->addWidget(rightmotortemp);

        qiyaval = new QCheckBox(centralWidget);
        qiyaval->setObjectName(QStringLiteral("qiyaval"));

        horizontalLayout_10->addWidget(qiyaval);

        robotx = new QCheckBox(centralWidget);
        robotx->setObjectName(QStringLiteral("robotx"));

        horizontalLayout_10->addWidget(robotx);

        roboty = new QCheckBox(centralWidget);
        roboty->setObjectName(QStringLiteral("roboty"));

        horizontalLayout_10->addWidget(roboty);

        heading = new QCheckBox(centralWidget);
        heading->setObjectName(QStringLiteral("heading"));

        horizontalLayout_10->addWidget(heading);

        leftdrivertemp = new QCheckBox(centralWidget);
        leftdrivertemp->setObjectName(QStringLiteral("leftdrivertemp"));

        horizontalLayout_10->addWidget(leftdrivertemp);

        rightdrivertemp = new QCheckBox(centralWidget);
        rightdrivertemp->setObjectName(QStringLiteral("rightdrivertemp"));

        horizontalLayout_10->addWidget(rightdrivertemp);

        crashstop = new QCheckBox(centralWidget);
        crashstop->setObjectName(QStringLiteral("crashstop"));

        horizontalLayout_10->addWidget(crashstop);

        estop = new QCheckBox(centralWidget);
        estop->setObjectName(QStringLiteral("estop"));

        horizontalLayout_10->addWidget(estop);

        motorpower = new QCheckBox(centralWidget);
        motorpower->setObjectName(QStringLiteral("motorpower"));

        horizontalLayout_10->addWidget(motorpower);

        crashval = new QCheckBox(centralWidget);
        crashval->setObjectName(QStringLiteral("crashval"));

        horizontalLayout_10->addWidget(crashval);


        gridLayout->addLayout(horizontalLayout_10, 1, 0, 1, 5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_11->addWidget(label);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(99999);
        spinBox->setSingleStep(1);

        horizontalLayout_11->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCustomPlot Scrollbar Axis Range Control Demo", 0));
        actionInsert_Plot->setText(QApplication::translate("MainWindow", "Insert Plot", 0));
        actionSave_Document->setText(QApplication::translate("MainWindow", "Save Document...", 0));
        openfile->setText(QApplication::translate("MainWindow", "openfile", 0));
        vel_teb->setText(QApplication::translate("MainWindow", "vel_teb", 0));
        omg_teb->setText(QApplication::translate("MainWindow", "omg_teb", 0));
        vel_teb_fb->setText(QApplication::translate("MainWindow", "vel_teb_fb", 0));
        omg_teb_fb->setText(QApplication::translate("MainWindow", "omg_teb_fb", 0));
        leftmotorspd->setText(QApplication::translate("MainWindow", "leftmotorspd", 0));
        rightmotorspd->setText(QApplication::translate("MainWindow", "rightmotorspd", 0));
        leftmotorspd_fb->setText(QApplication::translate("MainWindow", "leftmotorspd_fb", 0));
        rightmotorspd_fb->setText(QApplication::translate("MainWindow", "rightmotorspd_fb", 0));
        omg_imu->setText(QApplication::translate("MainWindow", "omg_imu", 0));
        omg_coder->setText(QApplication::translate("MainWindow", "omg_coder", 0));
        leftmotorstate->setText(QApplication::translate("MainWindow", "leftmotorstate", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", 0));
        dateTimeEditStart->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/M/d H:mm:ss", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        dateTimeEditEnd->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/M/d H:mm:ss", 0));
        rightmotorstate->setText(QApplication::translate("MainWindow", "rightmotorstate", 0));
        leftmotortemp->setText(QApplication::translate("MainWindow", "leftmotortemp", 0));
        rightmotortemp->setText(QApplication::translate("MainWindow", "rightmotortemp", 0));
        qiyaval->setText(QApplication::translate("MainWindow", "qiyaval", 0));
        robotx->setText(QApplication::translate("MainWindow", "robotx", 0));
        roboty->setText(QApplication::translate("MainWindow", "roboty", 0));
        heading->setText(QApplication::translate("MainWindow", "heading", 0));
        leftdrivertemp->setText(QApplication::translate("MainWindow", "leftdrivertemp", 0));
        rightdrivertemp->setText(QApplication::translate("MainWindow", "rightdrivertemp", 0));
        crashstop->setText(QApplication::translate("MainWindow", "crashstop", 0));
        estop->setText(QApplication::translate("MainWindow", "estop", 0));
        motorpower->setText(QApplication::translate("MainWindow", "motorpower", 0));
        crashval->setText(QApplication::translate("MainWindow", "crashval", 0));
        label->setText(QApplication::translate("MainWindow", "\347\272\265\350\275\264\346\234\200\345\244\247\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

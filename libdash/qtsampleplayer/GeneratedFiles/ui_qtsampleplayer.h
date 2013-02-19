/********************************************************************************
** Form generated from reading UI file 'qtsampleplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSAMPLEPLAYER_H
#define UI_QTSAMPLEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Renderer/QTGLRenderer.h"

QT_BEGIN_NAMESPACE

class Ui_QtSamplePlayerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBoxMPD;
    sampleplayer::renderer::QTGLRenderer *videoelement;
    QVBoxLayout *videoLayout;
    QWidget *w_controls;
    QVBoxLayout *verticalLayout;
    QWidget *w_boxes;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_start;
    QPushButton *button_stop;
    QLabel *label;
    QComboBox *cb_video_adaption;
    QLabel *label_2;
    QComboBox *cb_video_representation;
    QLabel *label_5;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSamplePlayerClass)
    {
        if (QtSamplePlayerClass->objectName().isEmpty())
            QtSamplePlayerClass->setObjectName(QStringLiteral("QtSamplePlayerClass"));
        QtSamplePlayerClass->setEnabled(true);
        QtSamplePlayerClass->resize(898, 516);
        centralWidget = new QWidget(QtSamplePlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setMinimumSize(QSize(600, 0));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        comboBoxMPD = new QComboBox(widget);
        comboBoxMPD->addItem(QStringLiteral("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/bunny_2s_480p_only/bunny_Desktop.mpd"));
        comboBoxMPD->addItem(QString());
        comboBoxMPD->setObjectName(QStringLiteral("comboBoxMPD"));

        verticalLayout_3->addWidget(comboBoxMPD);

        videoelement = new sampleplayer::renderer::QTGLRenderer(widget);
        videoelement->setObjectName(QStringLiteral("videoelement"));
        videoelement->setEnabled(true);
        videoelement->setMinimumSize(QSize(100, 100));
        videoLayout = new QVBoxLayout(videoelement);
        videoLayout->setSpacing(6);
        videoLayout->setContentsMargins(11, 11, 11, 11);
        videoLayout->setObjectName(QStringLiteral("videoLayout"));

        verticalLayout_3->addWidget(videoelement);


        horizontalLayout->addWidget(widget);

        w_controls = new QWidget(centralWidget);
        w_controls->setObjectName(QStringLiteral("w_controls"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(w_controls->sizePolicy().hasHeightForWidth());
        w_controls->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(w_controls);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        w_boxes = new QWidget(w_controls);
        w_boxes->setObjectName(QStringLiteral("w_boxes"));
        verticalLayout_2 = new QVBoxLayout(w_boxes);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        button_start = new QPushButton(w_boxes);
        button_start->setObjectName(QStringLiteral("button_start"));

        verticalLayout_2->addWidget(button_start);

        button_stop = new QPushButton(w_boxes);
        button_stop->setObjectName(QStringLiteral("button_stop"));

        verticalLayout_2->addWidget(button_stop);

        label = new QLabel(w_boxes);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        cb_video_adaption = new QComboBox(w_boxes);
        cb_video_adaption->setObjectName(QStringLiteral("cb_video_adaption"));

        verticalLayout_2->addWidget(cb_video_adaption);

        label_2 = new QLabel(w_boxes);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        cb_video_representation = new QComboBox(w_boxes);
        cb_video_representation->setObjectName(QStringLiteral("cb_video_representation"));
        cb_video_representation->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(cb_video_representation);

        label_5 = new QLabel(w_boxes);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        progressBar = new QProgressBar(w_boxes);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(w_boxes);


        horizontalLayout->addWidget(w_controls);

        QtSamplePlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtSamplePlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 898, 21));
        QtSamplePlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtSamplePlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtSamplePlayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtSamplePlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtSamplePlayerClass->setStatusBar(statusBar);

        retranslateUi(QtSamplePlayerClass);

        QMetaObject::connectSlotsByName(QtSamplePlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSamplePlayerClass)
    {
        QtSamplePlayerClass->setWindowTitle(QApplication::translate("QtSamplePlayerClass", "QtSamplePlayer", 0));
        comboBoxMPD->setItemText(1, QApplication::translate("QtSamplePlayerClass", "http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_2_resolutions.mpd", 0));

        button_start->setText(QApplication::translate("QtSamplePlayerClass", "Start", 0));
        button_stop->setText(QApplication::translate("QtSamplePlayerClass", "Stop", 0));
        label->setText(QApplication::translate("QtSamplePlayerClass", "Video AdaptationSet", 0));
        label_2->setText(QApplication::translate("QtSamplePlayerClass", "Video Representation", 0));
        label_5->setText(QApplication::translate("QtSamplePlayerClass", "Buffer", 0));
    } // retranslateUi

};

namespace Ui {
    class QtSamplePlayerClass: public Ui_QtSamplePlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSAMPLEPLAYER_H

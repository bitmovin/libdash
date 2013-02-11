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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSamplePlayerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QWidget *widget_2;
    QWidget *w_controls;
    QVBoxLayout *verticalLayout;
    QWidget *w_boxes;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *cb_video_adaption;
    QLabel *label_2;
    QComboBox *cb_video_representation;
    QLabel *label_3;
    QComboBox *cb_audio_adaption;
    QLabel *label_4;
    QComboBox *cb_audio_representation;
    QLabel *label_5;
    QProgressBar *progressBar;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSamplePlayerClass)
    {
        if (QtSamplePlayerClass->objectName().isEmpty())
            QtSamplePlayerClass->setObjectName(QStringLiteral("QtSamplePlayerClass"));
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
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setText(QStringLiteral("http://somedash.mpd"));

        verticalLayout_3->addWidget(lineEdit);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout_3->addWidget(widget_2);


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

        verticalLayout_2->addWidget(cb_video_representation);

        label_3 = new QLabel(w_boxes);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        cb_audio_adaption = new QComboBox(w_boxes);
        cb_audio_adaption->setObjectName(QStringLiteral("cb_audio_adaption"));

        verticalLayout_2->addWidget(cb_audio_adaption);

        label_4 = new QLabel(w_boxes);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        cb_audio_representation = new QComboBox(w_boxes);
        cb_audio_representation->setObjectName(QStringLiteral("cb_audio_representation"));

        verticalLayout_2->addWidget(cb_audio_representation);

        label_5 = new QLabel(w_boxes);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        progressBar = new QProgressBar(w_boxes);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);


        verticalLayout->addWidget(w_boxes);

        tableWidget = new QTableWidget(w_controls);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);


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
        label->setText(QApplication::translate("QtSamplePlayerClass", "Video Adaption", 0));
        label_2->setText(QApplication::translate("QtSamplePlayerClass", "Video Representation", 0));
        label_3->setText(QApplication::translate("QtSamplePlayerClass", "Audio Adaption", 0));
        label_4->setText(QApplication::translate("QtSamplePlayerClass", "Audio Representation", 0));
        label_5->setText(QApplication::translate("QtSamplePlayerClass", "Buffer", 0));
    } // retranslateUi

};

namespace Ui {
    class QtSamplePlayerClass: public Ui_QtSamplePlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSAMPLEPLAYER_H

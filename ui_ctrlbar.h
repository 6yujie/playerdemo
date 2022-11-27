/********************************************************************************
** Form generated from reading UI file 'ctrlbar.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLBAR_H
#define UI_CTRLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include "CustomSlider.h"

QT_BEGIN_NAMESPACE

class Ui_CtrlBar
{
public:
    QGridLayout *gridLayout_3;
    QWidget *PlaySliderBgWidget;
    QHBoxLayout *horizontalLayout;
    CustomSlider *PlaySlider;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *VolumeBtn;
    CustomSlider *VolumeSlider;
    QGridLayout *gridLayout;
    QLabel *TimeSplitLabel;
    QTimeEdit *VideoTotalTimeTimeEdit;
    QPushButton *ForwardBtn;
    QPushButton *BackwardBtn;
    QPushButton *StopBtn;
    QTimeEdit *VideoPlayTimeTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PlayOrPauseBtn;
    QPushButton *SettingBtn;
    QPushButton *PlaylistCtrlBtn;

    void setupUi(QWidget *CtrlBar)
    {
        if (CtrlBar->objectName().isEmpty())
            CtrlBar->setObjectName(QStringLiteral("CtrlBar"));
        CtrlBar->resize(594, 60);
        CtrlBar->setMaximumSize(QSize(16777215, 60));
        gridLayout_3 = new QGridLayout(CtrlBar);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        PlaySliderBgWidget = new QWidget(CtrlBar);
        PlaySliderBgWidget->setObjectName(QStringLiteral("PlaySliderBgWidget"));
        PlaySliderBgWidget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(PlaySliderBgWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 0, 0, 0);
        PlaySlider = new CustomSlider(PlaySliderBgWidget);
        PlaySlider->setObjectName(QStringLiteral("PlaySlider"));
        PlaySlider->setMaximum(65536);
        PlaySlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(PlaySlider);

        widget_2 = new QWidget(PlaySliderBgWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(108, 25));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        VolumeBtn = new QPushButton(widget_2);
        VolumeBtn->setObjectName(QStringLiteral("VolumeBtn"));
        VolumeBtn->setMinimumSize(QSize(20, 20));
        VolumeBtn->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(VolumeBtn, 0, 0, 1, 1);

        VolumeSlider = new CustomSlider(widget_2);
        VolumeSlider->setObjectName(QStringLiteral("VolumeSlider"));
        VolumeSlider->setMinimumSize(QSize(80, 25));
        VolumeSlider->setMaximumSize(QSize(80, 25));
        VolumeSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(VolumeSlider, 0, 1, 1, 1);


        horizontalLayout->addWidget(widget_2);


        gridLayout_3->addWidget(PlaySliderBgWidget, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        TimeSplitLabel = new QLabel(CtrlBar);
        TimeSplitLabel->setObjectName(QStringLiteral("TimeSplitLabel"));
        TimeSplitLabel->setMaximumSize(QSize(8, 16777215));

        gridLayout->addWidget(TimeSplitLabel, 0, 5, 1, 1);

        VideoTotalTimeTimeEdit = new QTimeEdit(CtrlBar);
        VideoTotalTimeTimeEdit->setObjectName(QStringLiteral("VideoTotalTimeTimeEdit"));
        VideoTotalTimeTimeEdit->setMaximumSize(QSize(70, 16777215));
        VideoTotalTimeTimeEdit->setWrapping(false);
        VideoTotalTimeTimeEdit->setFrame(false);
        VideoTotalTimeTimeEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        VideoTotalTimeTimeEdit->setReadOnly(true);
        VideoTotalTimeTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        VideoTotalTimeTimeEdit->setKeyboardTracking(true);

        gridLayout->addWidget(VideoTotalTimeTimeEdit, 0, 6, 1, 1);

        ForwardBtn = new QPushButton(CtrlBar);
        ForwardBtn->setObjectName(QStringLiteral("ForwardBtn"));
        ForwardBtn->setMinimumSize(QSize(30, 30));
        ForwardBtn->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(ForwardBtn, 0, 3, 1, 1);

        BackwardBtn = new QPushButton(CtrlBar);
        BackwardBtn->setObjectName(QStringLiteral("BackwardBtn"));
        BackwardBtn->setMinimumSize(QSize(30, 30));
        BackwardBtn->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(BackwardBtn, 0, 2, 1, 1);

        StopBtn = new QPushButton(CtrlBar);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setMinimumSize(QSize(30, 30));
        StopBtn->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(StopBtn, 0, 1, 1, 1);

        VideoPlayTimeTimeEdit = new QTimeEdit(CtrlBar);
        VideoPlayTimeTimeEdit->setObjectName(QStringLiteral("VideoPlayTimeTimeEdit"));
        VideoPlayTimeTimeEdit->setMaximumSize(QSize(70, 16777215));
        VideoPlayTimeTimeEdit->setFrame(false);
        VideoPlayTimeTimeEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        VideoPlayTimeTimeEdit->setReadOnly(true);
        VideoPlayTimeTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(VideoPlayTimeTimeEdit, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        PlayOrPauseBtn = new QPushButton(CtrlBar);
        PlayOrPauseBtn->setObjectName(QStringLiteral("PlayOrPauseBtn"));
        PlayOrPauseBtn->setMinimumSize(QSize(30, 30));
        PlayOrPauseBtn->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(PlayOrPauseBtn, 0, 0, 1, 1);

        SettingBtn = new QPushButton(CtrlBar);
        SettingBtn->setObjectName(QStringLiteral("SettingBtn"));
        SettingBtn->setMinimumSize(QSize(30, 30));
        SettingBtn->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(SettingBtn, 0, 9, 1, 1);

        PlaylistCtrlBtn = new QPushButton(CtrlBar);
        PlaylistCtrlBtn->setObjectName(QStringLiteral("PlaylistCtrlBtn"));
        PlaylistCtrlBtn->setMinimumSize(QSize(30, 30));
        PlaylistCtrlBtn->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setPointSize(20);
        PlaylistCtrlBtn->setFont(font);

        gridLayout->addWidget(PlaylistCtrlBtn, 0, 8, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(CtrlBar);

        QMetaObject::connectSlotsByName(CtrlBar);
    } // setupUi

    void retranslateUi(QWidget *CtrlBar)
    {
        CtrlBar->setWindowTitle(QApplication::translate("CtrlBar", "Form", nullptr));
        VolumeBtn->setText(QString());
        TimeSplitLabel->setText(QApplication::translate("CtrlBar", "/", nullptr));
        VideoTotalTimeTimeEdit->setDisplayFormat(QApplication::translate("CtrlBar", "HH:mm:ss", nullptr));
        ForwardBtn->setText(QString());
        BackwardBtn->setText(QString());
        StopBtn->setText(QString());
        VideoPlayTimeTimeEdit->setDisplayFormat(QApplication::translate("CtrlBar", "HH:mm:ss", nullptr));
        PlayOrPauseBtn->setText(QString());
        SettingBtn->setText(QString());
        PlaylistCtrlBtn->setText(QApplication::translate("CtrlBar", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CtrlBar: public Ui_CtrlBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLBAR_H

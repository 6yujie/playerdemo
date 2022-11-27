/********************************************************************************
** Form generated from reading UI file 'mainwid.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWID_H
#define UI_MAINWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <ctrlbar.h>
#include <show.h>

QT_BEGIN_NAMESPACE

class Ui_MainWid
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QWidget *ShowCtrlBarPlaylistBgWidget;
    QGridLayout *gridLayout;
    CtrlBar *CtrlBarWid;
    Show *ShowWid;
    QMenuBar *menubar;
    QDockWidget *PlaylistWid;
    QWidget *PlaylistContents;
    QStatusBar *statusbar;
    QDockWidget *TitleWid;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWid)
    {
        if (MainWid->objectName().isEmpty())
            MainWid->setObjectName(QStringLiteral("MainWid"));
        MainWid->resize(800, 500);
        centralwidget = new QWidget(MainWid);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ShowCtrlBarPlaylistBgWidget = new QWidget(centralwidget);
        ShowCtrlBarPlaylistBgWidget->setObjectName(QStringLiteral("ShowCtrlBarPlaylistBgWidget"));
        gridLayout = new QGridLayout(ShowCtrlBarPlaylistBgWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        CtrlBarWid = new CtrlBar(ShowCtrlBarPlaylistBgWidget);
        CtrlBarWid->setObjectName(QStringLiteral("CtrlBarWid"));
        CtrlBarWid->setMinimumSize(QSize(0, 60));
        CtrlBarWid->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(CtrlBarWid, 1, 0, 1, 1);

        ShowWid = new Show(ShowCtrlBarPlaylistBgWidget);
        ShowWid->setObjectName(QStringLiteral("ShowWid"));
        ShowWid->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(ShowWid, 0, 0, 1, 1);


        gridLayout_3->addWidget(ShowCtrlBarPlaylistBgWidget, 0, 0, 1, 1);

        MainWid->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWid);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWid->setMenuBar(menubar);
        PlaylistWid = new QDockWidget(MainWid);
        PlaylistWid->setObjectName(QStringLiteral("PlaylistWid"));
        PlaylistWid->setLayoutDirection(Qt::LeftToRight);
        PlaylistWid->setAutoFillBackground(false);
        PlaylistContents = new QWidget();
        PlaylistContents->setObjectName(QStringLiteral("PlaylistContents"));
        PlaylistContents->setStyleSheet(QStringLiteral(""));
        PlaylistWid->setWidget(PlaylistContents);
        MainWid->addDockWidget(static_cast<Qt::DockWidgetArea>(2), PlaylistWid);
        statusbar = new QStatusBar(MainWid);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWid->setStatusBar(statusbar);
        TitleWid = new QDockWidget(MainWid);
        TitleWid->setObjectName(QStringLiteral("TitleWid"));
        TitleWid->setLayoutDirection(Qt::LeftToRight);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        TitleWid->setWidget(dockWidgetContents);
        MainWid->addDockWidget(static_cast<Qt::DockWidgetArea>(4), TitleWid);

        retranslateUi(MainWid);

        QMetaObject::connectSlotsByName(MainWid);
    } // setupUi

    void retranslateUi(QMainWindow *MainWid)
    {
        MainWid->setWindowTitle(QApplication::translate("MainWid", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWid: public Ui_MainWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWID_H

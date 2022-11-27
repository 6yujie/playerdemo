/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <medialist.h>

QT_BEGIN_NAMESPACE

class Ui_Playlist
{
public:
    QGridLayout *gridLayout;
    MediaList *List;

    void setupUi(QWidget *Playlist)
    {
        if (Playlist->objectName().isEmpty())
            Playlist->setObjectName(QStringLiteral("Playlist"));
        Playlist->resize(115, 254);
        gridLayout = new QGridLayout(Playlist);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 1, 0, 0);
        List = new MediaList(Playlist);
        new QListWidgetItem(List);
        new QListWidgetItem(List);
        new QListWidgetItem(List);
        List->setObjectName(QStringLiteral("List"));
        List->setFocusPolicy(Qt::NoFocus);
        List->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        List->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(List, 0, 0, 1, 1);


        retranslateUi(Playlist);

        QMetaObject::connectSlotsByName(Playlist);
    } // setupUi

    void retranslateUi(QWidget *Playlist)
    {
        Playlist->setWindowTitle(QApplication::translate("Playlist", "Form", nullptr));

        const bool __sortingEnabled = List->isSortingEnabled();
        List->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = List->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Playlist", "testlist0", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = List->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Playlist", "testlist1", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = List->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Playlist", "testlist2", nullptr));
        List->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Playlist: public Ui_Playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H

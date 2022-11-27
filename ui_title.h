/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Title
{
public:
    QGridLayout *gridLayout;
    QLabel *MovieNameLab;
    QPushButton *MaxBtn;
    QPushButton *CloseBtn;
    QPushButton *FullScreenBtn;
    QPushButton *MinBtn;
    QPushButton *MenuBtn;

    void setupUi(QWidget *Title)
    {
        if (Title->objectName().isEmpty())
            Title->setObjectName(QStringLiteral("Title"));
        Title->resize(826, 50);
        Title->setMaximumSize(QSize(16777215, 50));
        gridLayout = new QGridLayout(Title);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MovieNameLab = new QLabel(Title);
        MovieNameLab->setObjectName(QStringLiteral("MovieNameLab"));
        MovieNameLab->setMargin(15);

        gridLayout->addWidget(MovieNameLab, 0, 1, 1, 1);

        MaxBtn = new QPushButton(Title);
        MaxBtn->setObjectName(QStringLiteral("MaxBtn"));
        MaxBtn->setMinimumSize(QSize(50, 50));
        MaxBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(MaxBtn, 0, 3, 1, 1);

        CloseBtn = new QPushButton(Title);
        CloseBtn->setObjectName(QStringLiteral("CloseBtn"));
        CloseBtn->setMinimumSize(QSize(50, 50));
        CloseBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(CloseBtn, 0, 5, 1, 1);

        FullScreenBtn = new QPushButton(Title);
        FullScreenBtn->setObjectName(QStringLiteral("FullScreenBtn"));
        FullScreenBtn->setMinimumSize(QSize(50, 50));
        FullScreenBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(FullScreenBtn, 0, 4, 1, 1);

        MinBtn = new QPushButton(Title);
        MinBtn->setObjectName(QStringLiteral("MinBtn"));
        MinBtn->setMinimumSize(QSize(50, 50));
        MinBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(MinBtn, 0, 2, 1, 1);

        MenuBtn = new QPushButton(Title);
        MenuBtn->setObjectName(QStringLiteral("MenuBtn"));
        MenuBtn->setMinimumSize(QSize(130, 0));
        MenuBtn->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light SemiCondensed"));
        font.setPointSize(18);
        MenuBtn->setFont(font);

        gridLayout->addWidget(MenuBtn, 0, 0, 1, 1);


        retranslateUi(Title);

        QMetaObject::connectSlotsByName(Title);
    } // setupUi

    void retranslateUi(QWidget *Title)
    {
        Title->setWindowTitle(QApplication::translate("Title", "Form", nullptr));
        MovieNameLab->setText(QApplication::translate("Title", "movie_name", nullptr));
        MaxBtn->setText(QString());
        CloseBtn->setText(QString());
        FullScreenBtn->setText(QString());
        MinBtn->setText(QString());
        MenuBtn->setText(QApplication::translate("Title", "PlayerDemo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Title: public Ui_Title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H

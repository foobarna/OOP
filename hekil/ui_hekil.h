/********************************************************************************
** Form generated from reading UI file 'hekil.ui'
**
** Created: Fri May 18 10:13:33 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEKIL_H
#define UI_HEKIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hekilClass
{
public:
    QPushButton *saveBtn;
    QPushButton *delBtn;
    QLineEdit *mTitle;
    QLineEdit *mType;
    QLineEdit *mDesc;
    QLineEdit *mAv;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *upBtn;
    QListWidget *listMovie;

    void setupUi(QWidget *hekilClass)
    {
        if (hekilClass->objectName().isEmpty())
            hekilClass->setObjectName(QString::fromUtf8("hekilClass"));
        hekilClass->resize(470, 311);
        saveBtn = new QPushButton(hekilClass);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(390, 150, 75, 23));
        delBtn = new QPushButton(hekilClass);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        delBtn->setGeometry(QRect(190, 250, 75, 23));
        mTitle = new QLineEdit(hekilClass);
        mTitle->setObjectName(QString::fromUtf8("mTitle"));
        mTitle->setGeometry(QRect(350, 30, 113, 20));
        mType = new QLineEdit(hekilClass);
        mType->setObjectName(QString::fromUtf8("mType"));
        mType->setGeometry(QRect(350, 60, 113, 20));
        mDesc = new QLineEdit(hekilClass);
        mDesc->setObjectName(QString::fromUtf8("mDesc"));
        mDesc->setGeometry(QRect(350, 90, 113, 20));
        mAv = new QLineEdit(hekilClass);
        mAv->setObjectName(QString::fromUtf8("mAv"));
        mAv->setGeometry(QRect(350, 120, 113, 20));
        mAv->setCursor(QCursor(Qt::IBeamCursor));
        mAv->setInputMethodHints(Qt::ImhPreferNumbers);
        mAv->setMaxLength(1);
        label = new QLabel(hekilClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 34, 46, 13));
        label_2 = new QLabel(hekilClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 65, 46, 13));
        label_3 = new QLabel(hekilClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 94, 61, 16));
        label_4 = new QLabel(hekilClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 126, 61, 16));
        upBtn = new QPushButton(hekilClass);
        upBtn->setObjectName(QString::fromUtf8("upBtn"));
        upBtn->setGeometry(QRect(20, 250, 75, 23));
        listMovie = new QListWidget(hekilClass);
        listMovie->setObjectName(QString::fromUtf8("listMovie"));
        listMovie->setGeometry(QRect(10, 30, 256, 192));

        retranslateUi(hekilClass);

        QMetaObject::connectSlotsByName(hekilClass);
    } // setupUi

    void retranslateUi(QWidget *hekilClass)
    {
        hekilClass->setWindowTitle(QApplication::translate("hekilClass", "hekil", 0, QApplication::UnicodeUTF8));
        saveBtn->setText(QApplication::translate("hekilClass", "Save", 0, QApplication::UnicodeUTF8));
        delBtn->setText(QApplication::translate("hekilClass", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("hekilClass", "Title", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("hekilClass", "Type", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("hekilClass", "Description", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("hekilClass", "Availability", 0, QApplication::UnicodeUTF8));
        upBtn->setText(QApplication::translate("hekilClass", "Update", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class hekilClass: public Ui_hekilClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEKIL_H

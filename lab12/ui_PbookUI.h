/********************************************************************************
** Form generated from reading UI file 'PbookUI.ui'
**
** Created: Fri May 25 14:35:02 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PBOOKUI_H
#define UI_PBOOKUI_H

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

class Ui_PbookUIClass
{
public:
    QListWidget *list;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PbookUIClass)
    {
        if (PbookUIClass->objectName().isEmpty())
            PbookUIClass->setObjectName(QString::fromUtf8("PbookUIClass"));
        PbookUIClass->resize(400, 300);
        list = new QListWidget(PbookUIClass);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 381, 161));
        lineEdit = new QLineEdit(PbookUIClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 180, 141, 28));
        lineEdit_2 = new QLineEdit(PbookUIClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 220, 141, 28));
        lineEdit_3 = new QLineEdit(PbookUIClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 260, 141, 28));
        label = new QLabel(PbookUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 190, 70, 18));
        label_2 = new QLabel(PbookUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 230, 70, 18));
        label_3 = new QLabel(PbookUIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 270, 81, 18));
        lineEdit_4 = new QLineEdit(PbookUIClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(280, 180, 113, 28));
        pushButton = new QPushButton(PbookUIClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 220, 101, 27));
        pushButton_2 = new QPushButton(PbookUIClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 270, 101, 27));

        retranslateUi(PbookUIClass);

        QMetaObject::connectSlotsByName(PbookUIClass);
    } // setupUi

    void retranslateUi(QWidget *PbookUIClass)
    {
        PbookUIClass->setWindowTitle(QApplication::translate("PbookUIClass", "PbookUI", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PbookUIClass", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PbookUIClass", "No", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PbookUIClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PbookUIClass", "Filter", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("PbookUIClass", "Reload", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PbookUIClass: public Ui_PbookUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PBOOKUI_H

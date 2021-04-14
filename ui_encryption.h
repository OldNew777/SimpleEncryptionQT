/********************************************************************************
** Form generated from reading UI file 'encryption.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTION_H
#define UI_ENCRYPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_encryption
{
public:
    QPushButton *pushButtonchoose;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonstart;
    QLineEdit *textEditkey;
    QLineEdit *textEditfile;

    void setupUi(QWidget *encryption)
    {
        if (encryption->objectName().isEmpty())
            encryption->setObjectName(QString::fromUtf8("encryption"));
        encryption->resize(600, 300);
        pushButtonchoose = new QPushButton(encryption);
        pushButtonchoose->setObjectName(QString::fromUtf8("pushButtonchoose"));
        pushButtonchoose->setGeometry(QRect(490, 60, 91, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        pushButtonchoose->setFont(font);
        label = new QLabel(encryption);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        label->setFont(font1);
        label_2 = new QLabel(encryption);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 71, 41));
        label_2->setFont(font1);
        pushButtonstart = new QPushButton(encryption);
        pushButtonstart->setObjectName(QString::fromUtf8("pushButtonstart"));
        pushButtonstart->setGeometry(QRect(230, 210, 161, 41));
        pushButtonstart->setFont(font1);
        textEditkey = new QLineEdit(encryption);
        textEditkey->setObjectName(QString::fromUtf8("textEditkey"));
        textEditkey->setGeometry(QRect(130, 130, 351, 41));
        textEditkey->setEchoMode(QLineEdit::Password);
        textEditfile = new QLineEdit(encryption);
        textEditfile->setObjectName(QString::fromUtf8("textEditfile"));
        textEditfile->setGeometry(QRect(130, 60, 351, 41));
        textEditfile->setReadOnly(true);

        retranslateUi(encryption);

        QMetaObject::connectSlotsByName(encryption);
    } // setupUi

    void retranslateUi(QWidget *encryption)
    {
        encryption->setWindowTitle(QCoreApplication::translate("encryption", "\346\226\207\344\273\266\345\212\240\345\257\206", nullptr));
        pushButtonchoose->setText(QCoreApplication::translate("encryption", "\351\200\211\346\213\251\346\226\207\344\273\266...", nullptr));
        label->setText(QCoreApplication::translate("encryption", "\345\276\205\345\212\240\345\257\206\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("encryption", "\345\257\206\347\240\201", nullptr));
        pushButtonstart->setText(QCoreApplication::translate("encryption", "\345\212\240\345\257\206/\350\247\243\345\257\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class encryption: public Ui_encryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTION_H

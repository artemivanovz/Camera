/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *cameraLabel;
    QRadioButton *cameraONButton;
    QRadioButton *cameraOFFButton;
    QFormLayout *formLayout_2;
    QLabel *disaplayLabel;
    QRadioButton *displayONButton;
    QRadioButton *displayOFFButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *displayButton;
    QPushButton *cameraButton;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(16);
        sizePolicy1.setVerticalStretch(9);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(160, 90));

        gridLayout->addWidget(label, 0, 0, 2, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(50);
        formLayout->setVerticalSpacing(50);
        cameraLabel = new QLabel(centralwidget);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, cameraLabel);

        cameraONButton = new QRadioButton(centralwidget);
        cameraONButton->setObjectName(QString::fromUtf8("cameraONButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cameraONButton);

        cameraOFFButton = new QRadioButton(centralwidget);
        cameraOFFButton->setObjectName(QString::fromUtf8("cameraOFFButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cameraOFFButton);


        gridLayout->addLayout(formLayout, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        disaplayLabel = new QLabel(centralwidget);
        disaplayLabel->setObjectName(QString::fromUtf8("disaplayLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, disaplayLabel);

        displayONButton = new QRadioButton(centralwidget);
        displayONButton->setObjectName(QString::fromUtf8("displayONButton"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, displayONButton);

        displayOFFButton = new QRadioButton(centralwidget);
        displayOFFButton->setObjectName(QString::fromUtf8("displayOFFButton"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, displayOFFButton);


        gridLayout->addLayout(formLayout_2, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        displayButton = new QPushButton(centralwidget);
        displayButton->setObjectName(QString::fromUtf8("displayButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(displayButton->sizePolicy().hasHeightForWidth());
        displayButton->setSizePolicy(sizePolicy2);
        displayButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D2B48C; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\321\200\320\270\321\207\320\275\320\265\320\262\321\213\320\271 \320\276\321\202\321\202\320\265\320\275\320\276\320\272 \320\261\320\265\320\266\320\265\320\262\320\276\320\263\320\276 */\n"
"    border: 2px solid #A0522D; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\320\260\321\217 \320\276\320\272\320\260\320\275\321\202\320\276\320\262\320\272\320\260 */\n"
"    border-radius: 25px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"    font-family: 'Arial'; /* \320\250\320\270\321\200\320\276\320\272\320\270\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    font-weight: bold; /* \320\226\320\270\321\200\320\275"
                        "\321\213\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    padding: 10px 20px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    color: #8B4513; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #C19A6B; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #8B4513; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        horizontalLayout->addWidget(displayButton);

        cameraButton = new QPushButton(centralwidget);
        cameraButton->setObjectName(QString::fromUtf8("cameraButton"));
        sizePolicy2.setHeightForWidth(cameraButton->sizePolicy().hasHeightForWidth());
        cameraButton->setSizePolicy(sizePolicy2);
        cameraButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D2B48C; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\321\200\320\270\321\207\320\275\320\265\320\262\321\213\320\271 \320\276\321\202\321\202\320\265\320\275\320\276\320\272 \320\261\320\265\320\266\320\265\320\262\320\276\320\263\320\276 */\n"
"    border: 2px solid #A0522D; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\320\260\321\217 \320\276\320\272\320\260\320\275\321\202\320\276\320\262\320\272\320\260 */\n"
"    border-radius: 25px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"    font-family: 'Arial'; /* \320\250\320\270\321\200\320\276\320\272\320\270\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    font-weight: bold; /* \320\226\320\270\321\200\320\275"
                        "\321\213\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    padding: 10px 20px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    color: #8B4513; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #C19A6B; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #8B4513; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        horizontalLayout->addWidget(cameraButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D2B48C; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\321\200\320\270\321\207\320\275\320\265\320\262\321\213\320\271 \320\276\321\202\321\202\320\265\320\275\320\276\320\272 \320\261\320\265\320\266\320\265\320\262\320\276\320\263\320\276 */\n"
"    border: 2px solid #A0522D; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\320\260\321\217 \320\276\320\272\320\260\320\275\321\202\320\276\320\262\320\272\320\260 */\n"
"    border-radius: 25px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"    font-family: 'Arial'; /* \320\250\320\270\321\200\320\276\320\272\320\270\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    font-weight: bold; /* \320\226\320\270\321\200\320\275"
                        "\321\213\320\271 \321\210\321\200\320\270\321\204\321\202 */\n"
"    padding: 10px 20px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    color: #8B4513; /* \320\221\320\276\320\273\320\265\320\265 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #C19A6B; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #8B4513; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        cameraLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\220\320\234\320\225\320\240\320\220", nullptr));
        cameraONButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\232\320\233", nullptr));
        cameraOFFButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\253\320\232\320\233", nullptr));
        disaplayLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\240\320\220\320\235\320\241\320\233\320\257\320\246\320\230\320\257", nullptr));
        displayONButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\232\320\233", nullptr));
        displayOFFButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\253\320\232\320\233", nullptr));
#if QT_CONFIG(whatsthis)
        displayButton->setWhatsThis(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: beige;\n"
"    border-radius: 15px;\n"
"    font-family: 'Arial';\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f0e68c;\n"
"}", nullptr));
#endif // QT_CONFIG(whatsthis)
        displayButton->setText(QCoreApplication::translate("MainWindow", "\320\242\320\240\320\220\320\235\320\241\320\233\320\257\320\246\320\230\320\257 \320\222\320\232\320\233", nullptr));
#if QT_CONFIG(whatsthis)
        cameraButton->setWhatsThis(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: beige;\n"
"    border-radius: 15px;\n"
"    font-family: 'Arial';\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f0e68c;\n"
"}", nullptr));
#endif // QT_CONFIG(whatsthis)
        cameraButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\220\320\234\320\225\320\240\320\220 \320\222\320\232\320\233", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\237\320\240\320\220\320\222\320\232\320\220 \320\236 \320\241\320\236\320\241\320\242\320\236\320\257\320\235\320\230\320\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

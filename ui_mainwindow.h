/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *border;
    QLabel *border_2;
    QLabel *border_3;
    QLabel *border_4;
    QLabel *Snake;
    QLabel *counter;
    QLabel *food;
    QLabel *log;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(600, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        border = new QLabel(centralWidget);
        border->setObjectName(QStringLiteral("border"));
        border->setGeometry(QRect(0, 0, 600, 30));
        border->setStyleSheet(QStringLiteral("background-color: rgb(39, 39, 39);"));
        border_2 = new QLabel(centralWidget);
        border_2->setObjectName(QStringLiteral("border_2"));
        border_2->setGeometry(QRect(0, 570, 600, 30));
        border_2->setStyleSheet(QStringLiteral("background-color: rgb(39, 39, 39);"));
        border_3 = new QLabel(centralWidget);
        border_3->setObjectName(QStringLiteral("border_3"));
        border_3->setGeometry(QRect(0, 0, 30, 600));
        border_3->setStyleSheet(QStringLiteral("background-color: rgb(39, 39, 39);"));
        border_4 = new QLabel(centralWidget);
        border_4->setObjectName(QStringLiteral("border_4"));
        border_4->setGeometry(QRect(570, 0, 30, 600));
        border_4->setStyleSheet(QStringLiteral("background-color: rgb(39, 39, 39);"));
        Snake = new QLabel(centralWidget);
        Snake->setObjectName(QStringLiteral("Snake"));
        Snake->setGeometry(QRect(30, 540, 30, 30));
        Snake->setStyleSheet(QStringLiteral("background-color: rgb(170, 0, 0);"));
        counter = new QLabel(centralWidget);
        counter->setObjectName(QStringLiteral("counter"));
        counter->setGeometry(QRect(285, 0, 30, 30));
        QFont font;
        font.setPointSize(12);
        counter->setFont(font);
        counter->setStyleSheet(QLatin1String("background-color:blue;\n"
"color:black;"));
        food = new QLabel(centralWidget);
        food->setObjectName(QStringLiteral("food"));
        food->setGeometry(QRect(270, 270, 30, 30));
        food->setStyleSheet(QLatin1String("background-color:green;\n"
"border-radius: 15px;"));
        log = new QLabel(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(60, 0, 131, 21));
        log->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:transparent;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        border->setText(QString());
        border_2->setText(QString());
        border_3->setText(QString());
        border_4->setText(QString());
        Snake->setText(QString());
        counter->setText(QApplication::translate("MainWindow", "0", nullptr));
        food->setText(QString());
        log->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

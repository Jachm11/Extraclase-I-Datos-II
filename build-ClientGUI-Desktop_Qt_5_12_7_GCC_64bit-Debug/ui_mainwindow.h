/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *grafo;
    QLabel *dir;
    QLabel *cos;
    QLabel *cam;
    QPushButton *buscar;
    QPushButton *v0;
    QPushButton *v1;
    QPushButton *v7;
    QPushButton *v8;
    QPushButton *v2;
    QPushButton *v6;
    QPushButton *v3;
    QPushButton *v5;
    QPushButton *v4;
    QLabel *de;
    QLabel *hacia;
    QLabel *res;
    QLabel *deNum;
    QLabel *aNum;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1218, 703);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        grafo = new QLabel(centralwidget);
        grafo->setObjectName(QString::fromUtf8("grafo"));
        grafo->setGeometry(QRect(260, 30, 721, 341));
        grafo->setPixmap(QPixmap(QString::fromUtf8(":/img/graph.jpg")));
        dir = new QLabel(centralwidget);
        dir->setObjectName(QString::fromUtf8("dir"));
        dir->setGeometry(QRect(210, 440, 91, 31));
        QFont font;
        font.setPointSize(14);
        dir->setFont(font);
        cos = new QLabel(centralwidget);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setGeometry(QRect(590, 450, 67, 17));
        cos->setFont(font);
        cam = new QLabel(centralwidget);
        cam->setObjectName(QString::fromUtf8("cam"));
        cam->setGeometry(QRect(960, 440, 81, 21));
        cam->setFont(font);
        buscar = new QPushButton(centralwidget);
        buscar->setObjectName(QString::fromUtf8("buscar"));
        buscar->setGeometry(QRect(560, 630, 89, 25));
        v0 = new QPushButton(centralwidget);
        v0->setObjectName(QString::fromUtf8("v0"));
        v0->setEnabled(true);
        v0->setGeometry(QRect(270, 170, 61, 61));
        v0->setCursor(QCursor(Qt::PointingHandCursor));
        v0->setStyleSheet(QString::fromUtf8("#v0 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v0->setCheckable(false);
        v1 = new QPushButton(centralwidget);
        v1->setObjectName(QString::fromUtf8("v1"));
        v1->setEnabled(true);
        v1->setGeometry(QRect(400, 40, 61, 61));
        v1->setCursor(QCursor(Qt::PointingHandCursor));
        v1->setStyleSheet(QString::fromUtf8("#v1{\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v1->setCheckable(false);
        v7 = new QPushButton(centralwidget);
        v7->setObjectName(QString::fromUtf8("v7"));
        v7->setEnabled(true);
        v7->setGeometry(QRect(400, 300, 61, 61));
        v7->setCursor(QCursor(Qt::PointingHandCursor));
        v7->setStyleSheet(QString::fromUtf8("#v7{\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v7->setCheckable(false);
        v8 = new QPushButton(centralwidget);
        v8->setObjectName(QString::fromUtf8("v8"));
        v8->setEnabled(true);
        v8->setGeometry(QRect(590, 170, 61, 61));
        v8->setCursor(QCursor(Qt::PointingHandCursor));
        v8->setStyleSheet(QString::fromUtf8("#v8{\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v8->setCheckable(false);
        v2 = new QPushButton(centralwidget);
        v2->setObjectName(QString::fromUtf8("v2"));
        v2->setEnabled(true);
        v2->setGeometry(QRect(590, 40, 61, 61));
        v2->setCursor(QCursor(Qt::PointingHandCursor));
        v2->setStyleSheet(QString::fromUtf8("#v2 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v2->setCheckable(false);
        v6 = new QPushButton(centralwidget);
        v6->setObjectName(QString::fromUtf8("v6"));
        v6->setEnabled(true);
        v6->setGeometry(QRect(600, 300, 61, 61));
        v6->setCursor(QCursor(Qt::PointingHandCursor));
        v6->setStyleSheet(QString::fromUtf8("#v6 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v6->setCheckable(false);
        v3 = new QPushButton(centralwidget);
        v3->setObjectName(QString::fromUtf8("v3"));
        v3->setEnabled(true);
        v3->setGeometry(QRect(750, 40, 61, 61));
        v3->setCursor(QCursor(Qt::PointingHandCursor));
        v3->setStyleSheet(QString::fromUtf8("#v3 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v3->setCheckable(false);
        v5 = new QPushButton(centralwidget);
        v5->setObjectName(QString::fromUtf8("v5"));
        v5->setEnabled(true);
        v5->setGeometry(QRect(760, 300, 61, 61));
        v5->setCursor(QCursor(Qt::PointingHandCursor));
        v5->setStyleSheet(QString::fromUtf8("#v5 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        v5->setCheckable(false);
        v4 = new QPushButton(centralwidget);
        v4->setObjectName(QString::fromUtf8("v4"));
        v4->setEnabled(true);
        v4->setGeometry(QRect(900, 160, 61, 61));
        v4->setCursor(QCursor(Qt::PointingHandCursor));
        v4->setStyleSheet(QString::fromUtf8("#v4 {\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"\n"
""));
        v4->setCheckable(false);
        de = new QLabel(centralwidget);
        de->setObjectName(QString::fromUtf8("de"));
        de->setGeometry(QRect(90, 120, 51, 41));
        QFont font1;
        font1.setPointSize(20);
        de->setFont(font1);
        de->setCursor(QCursor(Qt::ArrowCursor));
        hacia = new QLabel(centralwidget);
        hacia->setObjectName(QString::fromUtf8("hacia"));
        hacia->setGeometry(QRect(1050, 120, 81, 41));
        hacia->setFont(font1);
        hacia->setCursor(QCursor(Qt::ArrowCursor));
        res = new QLabel(centralwidget);
        res->setObjectName(QString::fromUtf8("res"));
        res->setGeometry(QRect(210, 490, 821, 81));
        deNum = new QLabel(centralwidget);
        deNum->setObjectName(QString::fromUtf8("deNum"));
        deNum->setGeometry(QRect(90, 180, 61, 61));
        QFont font2;
        font2.setPointSize(25);
        deNum->setFont(font2);
        aNum = new QLabel(centralwidget);
        aNum->setObjectName(QString::fromUtf8("aNum"));
        aNum->setGeometry(QRect(1050, 170, 61, 61));
        aNum->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Djikstra Graph", nullptr));
        grafo->setText(QString());
        dir->setText(QApplication::translate("MainWindow", "Direcci\303\263n", nullptr));
        cos->setText(QApplication::translate("MainWindow", "Costo", nullptr));
        cam->setText(QApplication::translate("MainWindow", "Camino", nullptr));
        buscar->setText(QApplication::translate("MainWindow", "Buscar ruta", nullptr));
        v0->setText(QString());
        v1->setText(QString());
        v7->setText(QString());
        v8->setText(QString());
        v2->setText(QString());
        v6->setText(QString());
        v3->setText(QString());
        v5->setText(QString());
        v4->setText(QString());
        de->setText(QApplication::translate("MainWindow", "De:", nullptr));
        hacia->setText(QApplication::translate("MainWindow", "Hacia:", nullptr));
        res->setText(QString());
        deNum->setText(QString());
        aNum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

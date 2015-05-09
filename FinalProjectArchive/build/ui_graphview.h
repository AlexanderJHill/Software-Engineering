/********************************************************************************
** Form generated from reading UI file 'graphview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEW_H
#define UI_GRAPHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graphview
{
public:
    QAction *actionInsert_Plot;
    QAction *actionSave_Document;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QCustomPlot *plot_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QCustomPlot *plot_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QCustomPlot *plot_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QCustomPlot *plot_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_7;
    QCustomPlot *plot_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sbWidth;
    QLabel *label_2;
    QSpinBox *sbHeight;
    QCheckBox *cbUseCurrentSize;
    QTextEdit *textEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Graphview)
    {
        if (Graphview->objectName().isEmpty())
            Graphview->setObjectName(QStringLiteral("Graphview"));
        Graphview->resize(1103, 612);
        Graphview->setDocumentMode(false);
        actionInsert_Plot = new QAction(Graphview);
        actionInsert_Plot->setObjectName(QStringLiteral("actionInsert_Plot"));
        actionSave_Document = new QAction(Graphview);
        actionSave_Document->setObjectName(QStringLiteral("actionSave_Document"));
        centralWidget = new QWidget(Graphview);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(tab);
        plot->setObjectName(QStringLiteral("plot"));
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        plot_2 = new QCustomPlot(tab_2);
        plot_2->setObjectName(QStringLiteral("plot_2"));
        sizePolicy.setHeightForWidth(plot_2->sizePolicy().hasHeightForWidth());
        plot_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(plot_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        sizePolicy.setHeightForWidth(tab_3->sizePolicy().hasHeightForWidth());
        tab_3->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        plot_3 = new QCustomPlot(tab_3);
        plot_3->setObjectName(QStringLiteral("plot_3"));
        sizePolicy.setHeightForWidth(plot_3->sizePolicy().hasHeightForWidth());
        plot_3->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(plot_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        plot_4 = new QCustomPlot(tab_4);
        plot_4->setObjectName(QStringLiteral("plot_4"));
        sizePolicy.setHeightForWidth(plot_4->sizePolicy().hasHeightForWidth());
        plot_4->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(plot_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        plot_5 = new QCustomPlot(tab_5);
        plot_5->setObjectName(QStringLiteral("plot_5"));
        sizePolicy.setHeightForWidth(plot_5->sizePolicy().hasHeightForWidth());
        plot_5->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(plot_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_7 = new QGridLayout(tab_6);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        plot_6 = new QCustomPlot(tab_6);
        plot_6->setObjectName(QStringLiteral("plot_6"));
        sizePolicy.setHeightForWidth(plot_6->sizePolicy().hasHeightForWidth());
        plot_6->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(plot_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        sbWidth = new QSpinBox(centralWidget);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbWidth->sizePolicy().hasHeightForWidth());
        sbWidth->setSizePolicy(sizePolicy1);
        sbWidth->setMinimum(1);
        sbWidth->setMaximum(9999);
        sbWidth->setValue(480);

        horizontalLayout->addWidget(sbWidth);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sbHeight = new QSpinBox(centralWidget);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sizePolicy1.setHeightForWidth(sbHeight->sizePolicy().hasHeightForWidth());
        sbHeight->setSizePolicy(sizePolicy1);
        sbHeight->setMinimum(1);
        sbHeight->setMaximum(9999);
        sbHeight->setValue(340);

        horizontalLayout->addWidget(sbHeight);

        cbUseCurrentSize = new QCheckBox(centralWidget);
        cbUseCurrentSize->setObjectName(QStringLiteral("cbUseCurrentSize"));

        horizontalLayout->addWidget(cbUseCurrentSize);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(400, 0));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        Graphview->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Graphview);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Graphview->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Graphview);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Graphview->setStatusBar(statusBar);

        mainToolBar->addAction(actionInsert_Plot);
        mainToolBar->addAction(actionSave_Document);

        retranslateUi(Graphview);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Graphview);
    } // setupUi

    void retranslateUi(QMainWindow *Graphview)
    {
        Graphview->setWindowTitle(QApplication::translate("Graphview", "Report Editor", 0));
        actionInsert_Plot->setText(QApplication::translate("Graphview", "Insert Plot", 0));
        actionSave_Document->setText(QApplication::translate("Graphview", "Save Document...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Graphview", "Strategy Score", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Graphview", "Location 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Graphview", "Location 2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Graphview", "Location 3", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Graphview", "Location 4", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Graphview", "Location 5", 0));
        label->setText(QApplication::translate("Graphview", "<html><head/><body><p>Size of plot<br/>in document:</p></body></html>", 0));
        label_2->setText(QApplication::translate("Graphview", "x", 0));
        cbUseCurrentSize->setText(QApplication::translate("Graphview", "Use current", 0));
    } // retranslateUi

};

namespace Ui {
    class Graphview: public Ui_Graphview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEW_H

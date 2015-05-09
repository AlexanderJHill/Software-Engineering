/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSlider *fishers;
    QLineEdit *lineEdit_0;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *locations;
    QLineEdit *lineEdit_1;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *fishtypes;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QSlider *fishpop;
    QLineEdit *lineEdit_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QSlider *runtime;
    QLineEdit *lineEdit_4;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *weather;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *overcast;
    QRadioButton *rain;
    QRadioButton *snow;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *graphicsView;
    QPushButton *simulateButton;
    QPushButton *reportButton;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 710);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fishers = new QSlider(groupBox);
        fishers->setObjectName(QStringLiteral("fishers"));
        fishers->setMinimum(1);
        fishers->setMaximum(100);
        fishers->setValue(50);
        fishers->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(fishers);

        lineEdit_0 = new QLineEdit(groupBox);
        lineEdit_0->setObjectName(QStringLiteral("lineEdit_0"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_0->sizePolicy().hasHeightForWidth());
        lineEdit_0->setSizePolicy(sizePolicy);
        lineEdit_0->setMaximumSize(QSize(50, 16777215));
        lineEdit_0->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit_0);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(146, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        locations = new QSlider(groupBox);
        locations->setObjectName(QStringLiteral("locations"));
        locations->setMinimum(1);
        locations->setMaximum(5);
        locations->setValue(3);
        locations->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(locations);

        lineEdit_1 = new QLineEdit(groupBox);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        sizePolicy.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy);
        lineEdit_1->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(lineEdit_1);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(146, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fishtypes = new QSlider(groupBox);
        fishtypes->setObjectName(QStringLiteral("fishtypes"));
        fishtypes->setMinimum(1);
        fishtypes->setMaximum(10);
        fishtypes->setValue(5);
        fishtypes->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(fishtypes);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(146, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        fishpop = new QSlider(groupBox);
        fishpop->setObjectName(QStringLiteral("fishpop"));
        fishpop->setMinimum(1);
        fishpop->setMaximum(1000);
        fishpop->setValue(800);
        fishpop->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(fishpop);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(146, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        runtime = new QSlider(groupBox);
        runtime->setObjectName(QStringLiteral("runtime"));
        runtime->setMinimum(1);
        runtime->setMaximum(30);
        runtime->setValue(30);
        runtime->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(runtime);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(138, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        weather = new QGroupBox(groupBox);
        weather->setObjectName(QStringLiteral("weather"));
        weather->setCheckable(true);
        weather->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(weather);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        overcast = new QRadioButton(weather);
        overcast->setObjectName(QStringLiteral("overcast"));

        verticalLayout_3->addWidget(overcast);

        rain = new QRadioButton(weather);
        rain->setObjectName(QStringLiteral("rain"));

        verticalLayout_3->addWidget(rain);

        snow = new QRadioButton(weather);
        snow->setObjectName(QStringLiteral("snow"));

        verticalLayout_3->addWidget(snow);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(weather);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_4->addWidget(graphicsView);

        simulateButton = new QPushButton(groupBox_2);
        simulateButton->setObjectName(QStringLiteral("simulateButton"));

        verticalLayout_4->addWidget(simulateButton);

        reportButton = new QPushButton(groupBox_2);
        reportButton->setObjectName(QStringLiteral("reportButton"));

        verticalLayout_4->addWidget(reportButton);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox_2);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, plainTextEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fisher Sim", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Simulation Settings", 0));
        label->setText(QApplication::translate("MainWindow", "Fishers", 0));
        lineEdit_0->setPlaceholderText(QApplication::translate("MainWindow", "50", 0));
        label_2->setText(QApplication::translate("MainWindow", "Locations", 0));
        lineEdit_1->setPlaceholderText(QApplication::translate("MainWindow", "3", 0));
        label_3->setText(QApplication::translate("MainWindow", "Types of fish", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "5", 0));
        label_4->setText(QApplication::translate("MainWindow", "Fish Population", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "800", 0));
        label_5->setText(QApplication::translate("MainWindow", "Runtime (days)", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "30", 0));
        weather->setTitle(QApplication::translate("MainWindow", "Poor Weather", 0));
        overcast->setText(QApplication::translate("MainWindow", "Overcast", 0));
        rain->setText(QApplication::translate("MainWindow", "Rain", 0));
        snow->setText(QApplication::translate("MainWindow", "Snow", 0));
        groupBox_2->setTitle(QString());
        simulateButton->setText(QApplication::translate("MainWindow", "Simulate", 0));
        reportButton->setText(QApplication::translate("MainWindow", "Generate Report", 0));
        plainTextEdit->setDocumentTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

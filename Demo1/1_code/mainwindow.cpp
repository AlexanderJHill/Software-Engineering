#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    log("auto scrolling simulation log");
    for (int i=0;i<10;i++){
        log("log test");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::log(const QString& text){
    ui->plainTextEdit->appendPlainText(text); // Adds the message to the widget
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum()); // Scrolls to the bottom
}

void MainWindow::on_fishers_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_0->setText(s);
    log("[test] fisher value changed to " + s);
}


void MainWindow::on_locations_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_1->setText(s);
}

void MainWindow::on_fishtypes_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_2->setText(s);
}

void MainWindow::on_fishpop_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_3->setText(s);
}

void MainWindow::on_runtime_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_4->setText(s);
}

void MainWindow::on_lineEdit_0_textEdited(const QString &arg1)
{
    ui->fishers->setValue(arg1.toInt());
}

void MainWindow::on_lineEdit_1_textEdited(const QString &arg1)
{
    ui->locations->setValue(arg1.toInt());
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->fishtypes->setValue(arg1.toInt());
}

void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    ui->fishpop->setValue(arg1.toInt());
}

void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{
    ui->runtime->setValue(arg1.toInt());
}

void MainWindow::on_weather_clicked()
{
    if(ui->weather->isChecked()){
        log("[test] weather enabled");
        if(!(ui->overcast->isChecked() + ui->rain->isChecked() + ui->snow->isChecked()))
        ui->overcast->setChecked(1);
    }
    else{
        log("[test] weather disabled");
    }
}



void MainWindow::on_reportButton_clicked()
{

    graphview.show();

}

void MainWindow::on_simulateButton_clicked()
{

    fisherNum = ui->fishers->value();
    fishLoc = ui->locations->value();
    fishType = ui->fishtypes->value();
    fishPop = ui->fishpop->value();
    runtime = ui->runtime->value();
    if (!(ui->weather->isChecked()))
        fishTemp = 0;
    else if (ui->overcast->isChecked())
        fishTemp = 1;
    else if (ui->rain->isChecked())
        fishTemp = 2;
    else if (ui->snow->isChecked())
        fishTemp = 3;


    QString fishers = QString::number(getfisherNum());
    QString locations = QString::number(getfishLoc());
    QString fishpop = QString::number(getfishPop());
    QString types = QString::number(getfishType());
    QString runtime = QString::number(getRuntime());
    QString weather = QString::number(getfishTemp());

    log("Simulation started with the following settings...");
    log("Fishers - " + fishers);
    log("Locations - " + locations);
    log("Fish population - " + fishpop);
    log("Different fish types - " + types);
    log("Simulation runtime in days - " + runtime);
    log("Weather - " + weather);
    log("Weather enums      0 = good weather . . . 1 = overcast . . . 2 = rain . . . 3 = snow");

}


//code to display a save dialog
//
//QLabel *saveFileNameLabel;
//int frameStyle = QFrame::Sunken | QFrame::Panel;
//saveFileNameLabel = new QLabel;
//saveFileNameLabel->setFrameStyle(frameStyle);

//QFileDialog::Options options;
//     QString selectedFilter;
//     QString fileName = QFileDialog::getSaveFileName(this,
//                                 tr("Save File As"),
//                                 saveFileNameLabel->text(),
//                                 tr("All Files (*);;Text Files (*.txt)"),
//                                 &selectedFilter,
//                                 options);
//     if (!fileName.isEmpty())
//         saveFileNameLabel->setText(fileName);


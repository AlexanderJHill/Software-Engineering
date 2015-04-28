#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Agent/agent.h"
#include "../Agent/strategy.h"
#include "../Agent/randomgenerator.h"
#include "../Agent/spot.h"
#include <QtWidgets>
#include <iostream>
#include <stdio.h>
#include <QVector>

using namespace std;
QVector<double> final;
QVector<double> final2;
QVector<double> final3;
QVector<double> final4;
QVector<double> final5;
QVector<double> final6;
int time;
vector<Spot *> spots;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    log("Welcome to Fisher Sim!");
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

    if (simulated == false){
        log("ERROR - run a simulation first");
        return;
    }
    Graphview *graphview = new Graphview();
    graphview->show();
    graphview->printSettings(settings);
    final.clear();
    final2.clear();
    final3.clear();
}

void MainWindow::on_simulateButton_clicked()
{

    simulated = true;
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
    QString runtimes = QString::number(getRuntime());

    QString w;
    switch(fishTemp){
    case 0:
        w = "Sunny";
        break;
    case 1:
        w = "Overcast";
        break;
    case 2:
        w = "Rain";
        break;
    case 3:
        w = "Snow";
        break;
    }


    QString a = ("Fishers\t" + fishers + "\nLocations\t" + locations + "\nFish Population\t"
            + fishpop + "\nFish Types\t" + types + "\nRuntime\t" + runtimes + "\nWeather\t" + w);
    settings = ("Simulation settings:\n" + a);
    log ("Simulation started with the following settings...\n" + a);

    //clear the list
    list<Agent *> *allagent = getAllAgent();
    allagent->clear();
    list<Strategy *> *allstrat = getAllStrat();
    allstrat->clear();
    spots.clear();

    startSimulate(fisherNum, fishLoc, fishType, fishPop, fishTemp, runtime);

}

void MainWindow::startSimulate(int fisherNum, int fishLoc, int fishType, int fishPop, int fishTemp, int runtime)
{

    setTime(runtime);
    initStrategy();
    initAgent(fisherNum);
    int index = getAllAgent()->size();
    int rem = fisherNum%fishLoc;
    if(rem!=0){
    getAllAgent()->resize(index - rem);
    }

    QString a =  QString::number(fisherNum/fishLoc);
    log(a);
    //setting up agent for each spot
    list<Agent *>::iterator it = getAllAgent()->begin();
    while(it != getAllAgent()->end()){
        list<Agent *> subagent;
        for (int i=0; i < fisherNum/fishLoc; i++){
            Agent *curAgent = *it;
            subagent.push_back(curAgent);
            it++;
        }
        Spot *newSpot = new Spot(subagent);
        spots.push_back(newSpot);
        subagent.clear();
    }
        //assign the agent
        QString b = "Num of agent in list " + QString::number(getAllAgent()->size());
        log(b);
        for(int day = 1; day != runtime + 1; day++)
         {
             runAgentSimulation();
             calculateSpot(fisherNum, fishLoc);
         }

}

void MainWindow::calculateSpot(int fisherNum, int fishLoc ){

    int goFishing =0;
    vector<int> data;
    for (int i =0; i < fishLoc; i++){
      list<Agent *> agents = spots.at(i)->getAgents();
      for (list<Agent *>::iterator it = agents.begin(); it != agents.end(); it++)
      {
            Agent *curAgent = *it;
            if (curAgent->getDecision()== 1)
            {
                goFishing++;
            }
       }
      data.push_back(goFishing);
      goFishing = 0;
    }
    final.push_back(data.at(0));

    if (fishLoc == 2){
    final2.push_back(data.at(1));
    }
    if (fishLoc == 3){
    final2.push_back(data.at(1));
    final3.push_back(data.at(2));
    }

    //final4.push_back(data.at(3));
    //final5.push_back(data.at(4));
    //final6.push_back(data.at(5));

}


QVector<double>getNumber(){
    QVector<double> a = final;
    return a;
}
QVector<double>getNumber2(){
    QVector<double> a2 = final2;
    return a2;
}
QVector<double>getNumber3(){
    QVector<double> a3 = final3;
    return a3;
}

void setTime(int init){
    time = init;
}

int getTime(){
    return time;
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


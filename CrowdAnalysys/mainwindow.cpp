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
#include <math.h>

using namespace std;

// mainwindow made by
// David Lazaar
// Alexander Hill


QVector<double> final;
QVector<double> final2;
QVector<double> final3;
QVector<double> final4;
QVector<double> final5;
int time;
vector<Spot *> spots;
QVector<double> percentage;
QVector<double> percentage2;
QVector<double> percentage3;
QVector<double> percentage4;
QVector<double> percentage5;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);                      // sets up the ui described in mainwindow.ui
    ui->plainTextEdit->setReadOnly(true);   // makes the log read only

    // initilize the drawing scene
    drawing_scene = new QGraphicsScene;
    drawing_scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(drawing_scene);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    // allocate a new Drawing item and initilize it.
    RealTime = new Drawing(ui->graphicsView,drawing_scene);
    ResetRealTimeDisplay();



    log("Welcome to Fisher Sim!");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ResetRealTimeDisplay(void){
    timer->stop();
    RealTime->SetLocationPop(0,50);
    RealTime->SetLocationPop(1,0);
    RealTime->SetLocationPop(2,0);
    RealTime->SetLocationPop(3,0);
    RealTime->SetLocationPop(4,0);
    RealTime->SetLocationPop(5,0);
    RealTime->SetDay(0);
    RealTime->SetNumberOfLocations(3);
    RealTime->ReDraw();
}

void MainWindow::update(){
    static int tmp = 0;
    int numberOfLoc = ui->locations->value();
    int popLeft = ui->fishers->value();
    if(tmp < final.length()){
        RealTime->SetDay(tmp + 1);
        if(numberOfLoc > 0 && tmp < final.length()){
            RealTime->SetLocationPop(1,final.at(tmp));
            popLeft -= final.at(tmp);
        }
        if(numberOfLoc > 1 && tmp < final2.length()){
            RealTime->SetLocationPop(2,final2.at(tmp));
            popLeft -= final.at(tmp);
        }
        if(numberOfLoc > 2 && tmp < final3.length()){
            RealTime->SetLocationPop(3,final3.at(tmp));
            popLeft -= final.at(tmp);
        }
        if(numberOfLoc > 3 && tmp < final4.length()){
            RealTime->SetLocationPop(4,final4.at(tmp));
            popLeft -= final.at(tmp);
        }
        if(numberOfLoc > 4 && tmp < final5.length()){
            RealTime->SetLocationPop(5,final5.at(tmp));
            popLeft -= final.at(tmp);
        }

        RealTime->SetLocationPop(0,popLeft);
        tmp++;
    }else{
        timer->stop();
        tmp = 0;
    }
    RealTime->ReDraw();

}

void MainWindow::log(const QString& text){      // This function can print to the log
    ui->plainTextEdit->appendPlainText(text);   // Adds the message to the widget
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum()); // Scrolls to the bottom
}

// the functions below handle user input on our settings ui elements

void MainWindow::on_fishers_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_0->setText(s);
    RealTime->SetLocationPop(0,value);
    RealTime->ReDraw();
}


void MainWindow::on_locations_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->lineEdit_1->setText(s);

    RealTime->SetNumberOfLocations(value);

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
        if(!(ui->overcast->isChecked() || ui->rain->isChecked() || ui->snow->isChecked()))
        ui->overcast->setChecked(1);
    }

}



void MainWindow::on_reportButton_clicked()
{

    if (simulated == false){
        log("ERROR - run a simulation first");  // if a simulation has not been run first, we cannot generate reports
        return;
    }
    Graphview *graphview = new Graphview();     // instantiate graphview
    graphview->show();
    graphview->printSettings(settings);
    final.clear();
    final2.clear();
    final3.clear();
    final4.clear();
    final5.clear();
}

void MainWindow::on_simulateButton_clicked()
{

    final.clear();
    final2.clear();
    final3.clear();
    final4.clear();
    final5.clear();

    simulated = true;                       // a simulation has been run


    fisherNum = ui->fishers->value();       // these assignments get our user input from the ui elements
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


    QString fishers = QString::number(getfisherNum());     // convert to strings for printing
    QString locations = QString::number(getfishLoc());
    QString fishpop = QString::number(getfishPop());
    QString types = QString::number(getfishType());
    QString runtimes = QString::number(getRuntime());

    QString w;
    switch(fishTemp){   // resolve weather string
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


    QString a = ("Fishers\t" + fishers + "\nLocations\t" + locations + "\nFish Population\t"        // prepare a settings string to be set to graphview
            + fishpop + "\nFish Types\t" + types + "\nRuntime\t" + runtimes + "\nWeather\t" + w);
    settings = ("Simulation settings:\n" + a + "\n");
    log ("\nSimulation started with the following settings...\n" + a);

    //clear the list
    list<Agent *> *allagent = getAllAgent();
    allagent->clear();
    list<Strategy *> *allstrat = getAllStrat();
    allstrat->clear();
    spots.clear();

    startSimulate(fisherNum, fishLoc, fishType, fishPop, fishTemp, runtime);
    timer->start(1000); // start the timer to display the RealTime view

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
        
    for(int day = 1; day != runtime + 1; day++)
     {
         runAgentSimulation();
         calculateSpot(fisherNum, fishLoc);
     }

}

void MainWindow::calculateSpot(int fisherNum, int fishLoc ){
    int maxCap = fisherNum/fishLoc;
    int goFishing =0;
    vector<int> data;
    vector<int> percent;
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
      percent.push_back(crowdness(goFishing,maxCap));
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
    if(fishLoc == 4){
        final2.push_back(data.at(1));
        final3.push_back(data.at(2));
        final4.push_back(data.at(3));
    }
    if(fishLoc == 5){
        final2.push_back(data.at(1));
        final3.push_back(data.at(2));
        final4.push_back(data.at(3));
        final5.push_back(data.at(4));
    }

    percentage.push_back(percent.at(0));

    if (fishLoc == 2){
        percentage2.push_back(percent.at(1));
    }
    if (fishLoc == 3){
        percentage2.push_back(percent.at(1));
        percentage3.push_back(percent.at(2));
    }
    if(fishLoc == 4){
        percentage2.push_back(percent.at(1));
        percentage3.push_back(percent.at(2));
        percentage4.push_back(percent.at(3));
    }
    if(fishLoc == 5){
        percentage2.push_back(percent.at(1));
        percentage3.push_back(percent.at(2));
        percentage4.push_back(percent.at(3));
        percentage5.push_back(percent.at(4));
    }
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
QVector<double>getNumber4(){
    QVector<double> a = final4;
    return a;
}
QVector<double>getNumber5(){
    QVector<double> a2 = final5;
    return a2;
}
QVector<double>getCrowd(){
    QVector<double> a = percentage;
    return a;
}
QVector<double>getCrowd2(){
    QVector<double> a2 = percentage2;
    return a2;
}
QVector<double>getCrowd3(){
    QVector<double> a3 = percentage3;
    return a3;
}
QVector<double>getCrowd4(){
    QVector<double> a = percentage4;
    return a;
}
QVector<double>getCrowd5(){
    QVector<double> a2 = percentage5;
    return a2;
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


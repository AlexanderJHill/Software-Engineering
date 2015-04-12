#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Agent/agent.h"
#include "../Agent/strategy.h"
#include "../Agent/randomgenerator.h"
#include <QtWidgets>
#include <iostream>
#include <stdio.h>
using namespace std;


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
    QString runtime = QString::number(getRuntime());

    QString w;
    switch(fishTemp){
    case 0:
        w = "Sunny";
    case 1:
        w = "Overcast";
    case 2:
        w = "Rain";
    case 3:
        w = "Snow";
    }


    QString a = ("Fishers\t" + fishers + "\nLocations\t" + locations + "\nFish Population\t"
            + fishpop + "\nFish Types\t" + types + "\nRuntime\t" + runtime + "\nWeather\t" + w);
    settings = ("Simulation settings:\n" + a);
    log ("Simulation started with the following settings...\n" + a);

    //clear the list
    list<Agent *> *allagent = getAllAgent();
    allagent->clear();
    list<Strategy *> *allstrat = getAllStrat();
    allstrat->clear();

    startSimulate(fisherNum, fishLoc, fishType, fishPop, fishTemp);


}

void MainWindow::startSimulate(int fisherNum, int fishLoc, int fishType, int fishPop, int fishTemp)
{
    initStrategy();
    initAgent(fisherNum);
    QString a = "Num of agent in list " + QString::number(getAllAgent()->size());
    log(a);

    //testing...
    //****************************************************************************//
    list<Agent *> *allAgent = getAllAgent(); // holds all the dummy agent
    list<Agent *>::iterator it = allAgent->begin();
    Agent *agent1 = *it;
    it++;
    Agent *agent2 = *it;

    // printing agents' history
    vector<int> his1 = agent1->getHistory();
    vector<int> his2 = agent2->getHistory();

    int index1 = 0; //hold the row number for a strategy
    if (his1.at(2) == 1) index1 = index1 + 1;
    if (his1.at(1) == 1) index1 = index1 + 2;
    if (his1.at(0) == 1) index1 = index1 + 4;

    int index2 = 0; //hold the row number for a strategy
    if (his2.at(2) == 1) index2 = index2 + 1;
    if (his2.at(1) == 1) index2 = index2 + 2;
    if (his2.at(0) == 1) index2 = index2 + 4;

    cout << "History" << endl;
    printf("Agent 1: %2d %2d %2d", his1.at(0), his1.at(1), his1.at(2));
    printf("\tIndex of strategy: %d\n", index1);
    printf("Agent 2: %2d %2d %2d", his2.at(0), his2.at(1), his2.at(2));
    printf("\tIndex of strategy: %d\n", index2);

    // make early decision
    agent1->makeEarlyDecision();
    agent2->makeEarlyDecision();

    // printing agents' strategy
    vector<int> strat1 = agent1->getStrat().at(0)->getDecisionPattern();
    vector<int> strat2 = agent2->getStrat().at(0)->getDecisionPattern();

    cout << "\n\nAgent 1 Strategy       Agent 2 Strategy" << endl;
    for (int i = 0; i < strat1.size(); i++)
    {
        printf(" %-2d                     %-2d\n", strat1.at(i), strat2.at(i));
    }

    // print early decision
    cout << "\n\nAgents' Early Decision" << endl;
    cout << "Agent 1: " << agent1->getEarlyDecision() << endl;
    cout << "Agent 2: " << agent2->getEarlyDecision() << endl;

    // printing agents' threshold
    agent1->calcThreshold();
    agent2->calcThreshold();

    cout << "\n\nAgents' Threshold" << endl;
    cout << "Agent 1: " << agent1->getThreshold() << endl;
    cout << "Agent 2: " << agent2->getThreshold() << endl;

    // printing final decision
    agent1->makeDecision();
    agent2->makeDecision();
    cout << "\n\nAgents' Final Decision" << endl;
    cout << "Agent 1: " << agent1->getDecision() << endl;
    cout << "Agent 2: " << agent2->getDecision() << endl;

    // printing updated history
    agent1->updateHistory();
    agent2->updateHistory();
    vector<int> updatehis1 = agent1->getHistory();
    vector<int> updatehis2 = agent2->getHistory();
    cout << "\n\nUpdated History" << endl;
    printf("Agent 1: %2d %2d %2d\n", updatehis1.at(0), updatehis1.at(1), updatehis1.at(2));
    printf("Agent 2: %2d %2d %2d\n\n", updatehis2.at(0), updatehis2.at(1), updatehis2.at(2));

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


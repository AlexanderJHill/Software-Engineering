#include "Graphview.h"
#include "ui_graphview.h"
#include <QtGui>
#include "mainwindow.h"
#include "UserSettings.h"
#include "ui_mainwindow.h"
#include "../Agent/agent.h"
#include "../Agent/spot.h"
#include <QVector>



Graphview::Graphview(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::Graphview)
{
  ui->setupUi(this);
  connect(ui->cbUseCurrentSize, SIGNAL(toggled(bool)), ui->sbWidth, SLOT(setDisabled(bool)));
  connect(ui->cbUseCurrentSize, SIGNAL(toggled(bool)), ui->sbHeight, SLOT(setDisabled(bool)));

  ui->plot->axisRect()->setMinimumSize(300, 180);
  setupPlot();

  // register the plot document object (only needed once, no matter how many plots will be in the QTextDocument):
  QCPDocumentObject *plotObjectHandler = new QCPDocumentObject(this);
  ui->textEdit->document()->documentLayout()->registerHandler(QCPDocumentObject::PlotTextFormat, plotObjectHandler);
}

Graphview::~Graphview()
{
  delete ui;
}

void Graphview::printSettings(QString s){

    ui->textEdit->append(s);

}

void Graphview::setupPlot()
{
    /***********************************Strategy Scores***************************/
         //graph, strategy scores
         // create empty bar chart objects:
         QCPBars *fossil = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
         ui->plot->addPlottable(fossil);
         // set names and colors:
         QPen pen;
         pen.setWidthF(1.2);
         pen.setColor(QColor(255, 131, 0));
         fossil->setPen(pen);
         fossil->setBrush(QColor(255, 131, 0, 50));

         // prepare x axis with country labels:
         QVector<double> ticks;
         QVector<QString> labels;
         for (int i = 0; i < 20; i++){
              ticks << i+1;
         }
        labels <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20";
         ui->plot->xAxis->setAutoTicks(false);
         ui->plot->xAxis->setAutoTickLabels(false);
         ui->plot->xAxis->setTickVector(ticks);
         ui->plot->xAxis->setTickVectorLabels(labels);
         ui->plot->xAxis->setTickLabelRotation(60);
         ui->plot->xAxis->setSubTickCount(0);
         ui->plot->xAxis->setTickLength(0, 4);
         ui->plot->xAxis->grid()->setVisible(true);
         ui->plot->xAxis->setRange(0, 21);
         ui->plot->xAxis->setLabel("Strategy Number");

         // prepare y axis:
         ui->plot->yAxis->setRange(-50, 50);
         ui->plot->yAxis->setPadding(5); // a bit more space to the left border
         ui->plot->yAxis->setLabel("Strategy Score");
         ui->plot->yAxis->grid()->setSubGridVisible(true);
         QPen gridPen;
         gridPen.setStyle(Qt::SolidLine);
         gridPen.setColor(QColor(0, 0, 0, 25));
         ui->plot->yAxis->grid()->setPen(gridPen);
         gridPen.setStyle(Qt::DotLine);
         ui->plot->yAxis->grid()->setSubGridPen(gridPen);

         // Add data:
         QVector<double> crowdData;
              for(list<Strategy *>::iterator it = getAllStrat()->begin(); it != getAllStrat()->end(); it++)
              {
                  Strategy *curPoint = *it;
                  crowdData << curPoint->getScore();
              }

              fossil->setData(ticks, crowdData);

           ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
/**********************************Crowd per Spot ************************************/
    //Get data from main
    QVector<double> b = getNumber();
    QVector<double> b2 = getNumber2();
    QVector<double> b3 = getNumber3();

    int time= getTime();
    list<Agent *> *allagent = getAllAgent();
    list<Strategy *> *allstrat = getAllStrat();

 /************************ Spot 1**********************************************/
    // create empty bar chart objects:
    QCPBars *fossil2 = new QCPBars(ui->plot_2->xAxis, ui->plot_2->yAxis);
    ui->plot_2->addPlottable(fossil2);

    // set names and colors:
    QPen pen2;
    pen2.setWidthF(1.2);
    pen2.setColor(QColor(255, 131, 0));
    fossil2->setPen(pen2);
    fossil2->setBrush(QColor(255, 131, 0, 50));

    // prepare x axis with country labels:
    QVector<double> ticks2;
    QVector<QString> labels2;

    for (int i = 0; i < 24; i++){
        ticks2 << i;
    }
    labels2 <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"
 <<"21"<<"22"<<"23"<<"24";
    ui->plot_2->xAxis->setAutoTicks(false);
    ui->plot_2->xAxis->setAutoTickLabels(false);
    ui->plot_2->xAxis->setTickVector(ticks2);
    ui->plot_2->xAxis->setTickVectorLabels(labels2);
    ui->plot_2->xAxis->setTickLabelRotation(60);
    ui->plot_2->xAxis->setSubTickCount(0);
    ui->plot_2->xAxis->setTickLength(0, 8);
    ui->plot_2->xAxis->grid()->setVisible(true);
    ui->plot_2->xAxis->setRange(-1, time);
    ui->plot_2->xAxis->setLabel("Hour");

    // prepare y axis:
    ui->plot_2->yAxis->setRange(-1, 100);
    ui->plot_2->yAxis->setPadding(5); // a bit more space to the left border
    ui->plot_2->yAxis->setLabel("Crowd Percentage per Spot 1 (%)");
    ui->plot_2->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen2;
    gridPen2.setStyle(Qt::SolidLine);
    gridPen2.setColor(QColor(0, 0, 0, 25));
    ui->plot_2->yAxis->grid()->setPen(gridPen2);
    gridPen2.setStyle(Qt::DotLine);
    ui->plot_2->yAxis->grid()->setSubGridPen(gridPen2);

    //Add data;
    QVector<double> crowdData2;
    for (int i = 0; i < b.size(); i++){
        crowdData2<<b.at(i);
    }

    fossil2->setData(ticks2, crowdData2);
    ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

 /*****************Spot 2**********************************************/
/*    // create empty bar chart objects:
    QCPBars *fossil3 = new QCPBars(ui->plot_3->xAxis, ui->plot_3->yAxis);

    ui->plot_3->addPlottable(fossil3);

    // set names and colors:
    pen2.setWidthF(1.2);
    pen2.setColor(QColor(255, 131, 0));
    fossil3->setPen(pen2);
    fossil3->setBrush(QColor(255, 131, 0, 50));

    QVector<double> ticks3;
    QVector<QString> labels3;
    for (int i = 0; i < 24; i++){
        ticks3 << i;
    }
    labels3 <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"
    <<"21"<<"22"<<"23"<<"24";
    // prepare x axis with country labels:
    ui->plot_3->xAxis->setAutoTicks(false);
    ui->plot_3->xAxis->setAutoTickLabels(false);
    ui->plot_3->xAxis->setTickVector(ticks2);
    ui->plot_3->xAxis->setTickVectorLabels(labels3);
    ui->plot_3->xAxis->setTickLabelRotation(60);
    ui->plot_3->xAxis->setSubTickCount(0);
    ui->plot_3->xAxis->setTickLength(0, 8);
    ui->plot_3->xAxis->grid()->setVisible(true);
    ui->plot_3->xAxis->setRange(-1, time);
    ui->plot_3->xAxis->setLabel("Hour");

    // prepare y axis:
    ui->plot_3->yAxis->setRange(-1, 100);
    ui->plot_3->yAxis->setPadding(5); // a bit more space to the left border
    ui->plot_3->yAxis->setLabel("Crowd Percentage per Spot 2 (%)");
    ui->plot_3->yAxis->grid()->setSubGridVisible(true);
    gridPen2.setStyle(Qt::SolidLine);
    gridPen2.setColor(QColor(0, 0, 0, 25));
    ui->plot_3->yAxis->grid()->setPen(gridPen2);
    gridPen2.setStyle(Qt::DotLine);
    ui->plot_3->yAxis->grid()->setSubGridPen(gridPen2);

    // Add data:
    QVector<double> crowdData3;
    for (int i = 0; i < b2.size(); i++){
        crowdData3<<b2.at(i);
    }
    fossil3->setData(ticks3, crowdData3);

    ui->plot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    */
 /********************************SPot 3***************************************/
/*
    // create empty bar chart objects:
    QCPBars *fossil4 = new QCPBars(ui->plot_4->xAxis, ui->plot_4->yAxis);

    ui->plot_4->addPlottable(fossil4);

    // set names and colors:
    pen2.setWidthF(1.2);
    pen2.setColor(QColor(255, 131, 0));
    fossil3->setPen(pen2);
    fossil3->setBrush(QColor(255, 131, 0, 50));

    QVector<double> ticks4;
    QVector<QString> labels4;
    for (int i = 0; i < 24; i++){
        ticks4 << i;
    }
    labels4 <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"
    <<"21"<<"22"<<"23"<<"24";
    // prepare x axis with country labels:
    ui->plot_4->xAxis->setAutoTicks(false);
    ui->plot_4->xAxis->setAutoTickLabels(false);
    ui->plot_4->xAxis->setTickVector(ticks2);
    ui->plot_4->xAxis->setTickVectorLabels(labels4);
    ui->plot_4->xAxis->setTickLabelRotation(60);
    ui->plot_4->xAxis->setSubTickCount(0);
    ui->plot_4->xAxis->setTickLength(0, 8);
    ui->plot_4->xAxis->grid()->setVisible(true);
    ui->plot_4->xAxis->setRange(-1, time);
    ui->plot_4->xAxis->setLabel("Hour");

    // prepare y axis:
    ui->plot_4->yAxis->setRange(-1, 100);
    ui->plot_4->yAxis->setPadding(5); // a bit more space to the left border
    ui->plot_4->yAxis->setLabel("Crowd Percentage per Spot 3 (%)");
    ui->plot_4->yAxis->grid()->setSubGridVisible(true);
    gridPen2.setStyle(Qt::SolidLine);
    gridPen2.setColor(QColor(0, 0, 0, 25));
    ui->plot_4->yAxis->grid()->setPen(gridPen2);
    gridPen2.setStyle(Qt::DotLine);
    ui->plot_4->yAxis->grid()->setSubGridPen(gridPen2);

    // Add data:
    QVector<double> crowdData4;
    for (int i = 0; i < b3.size(); i++){
        crowdData4<<b3.at(i);
    }
    fossil4->setData(ticks4, crowdData4);

    ui->plot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
*/
  // Note: we could have also just called customPlot->rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
   // ui->plot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
   // ui->plot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->tabWidget->setCurrentIndex(0);

}


//!
//! \brief Graphview::on_actionInsert_Plot_triggered
//!
//!
//!
//!
void Graphview::on_actionInsert_Plot_triggered()
{
  QTextCursor cursor = ui->textEdit->textCursor();

  // insert the current plot at the cursor position. QCPDocumentObject::generatePlotFormat creates a
  // vectorized snapshot of the passed plot (with the specified width and height) which gets inserted
  // into the text document.
  double width = ui->cbUseCurrentSize->isChecked() ? 0 : ui->sbWidth->value();
  double height = ui->cbUseCurrentSize->isChecked() ? 0 : ui->sbHeight->value();

  int a = ui->tabWidget->currentIndex();
  switch (a){
      case 0:
          cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(ui->plot, width, height));
          break;
      case 1:
          cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(ui->plot_2, width, height));
          break;
  }

  ui->textEdit->setTextCursor(cursor);
}

void Graphview::on_actionSave_Document_triggered()
{
  QString filter = "PDF (*.pdf)";
  QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), filter);
  if (!fileName.isEmpty())
  {
    QPrinter printer;
    printer.setFullPage(true);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    ui->textEdit->document()->print(&printer);
  }
}

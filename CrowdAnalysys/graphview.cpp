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
         ui->plot->yAxis->setRange(-10, 101);
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
                  crowdData << curPoint->getWin();
              }

              fossil->setData(ticks, crowdData);

           ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

/**********************************Crowd per Spot Data ************************************/
    //Get data from main
    QVector<double> b = getCrowd();
    QVector<double> b2 = getCrowd2();
    QVector<double> b3 = getCrowd3();
    QVector<double> b4 = getCrowd4();
    QVector<double> b5 = getCrowd5();

    int time= getTime();
    list<Agent *> *allagent = getAllAgent();
    list<Strategy *> *allstrat = getAllStrat();
/***************************Spot 1 *******************************/
         ui->plot_2->addGraph();
         pen.setColor(QColor(qSin(1*1+1.2)*80+80, qSin(1*0.3+0)*80+80, qSin(1*0.3+1.5)*80+80));
         ui->plot_2->graph()->setPen(pen);
         //ui->plot_2->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
         ui->plot_2->graph()->setLineStyle((QCPGraph::LineStyle)1);
         ui->plot_2->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
         // generate data:
         QVector<double> x(time);
         QVector<QString> labels2;
         for (int i = 0; i < time; i++){
             x[i] = i;
         }
         labels2 <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"
         <<"21"<<"22"<<"23"<<"24"<<"25"<<"26"<<"27"<<"28"<<"29"<<"30";
         int j = b.size();

         QVector<double> y(j);
         for (int i = 0; i < j; i++){
              y[i]=b.at(i);
              }
         ui->plot_2->graph()->setData(x, y);
         //ui->plot_2->graph()->rescaleAxes(true);

         ui->plot_2->xAxis->setAutoTicks(false);
         ui->plot_2->xAxis->setAutoTickLabels(false);
         ui->plot_2->xAxis->setTickVector(x);
         ui->plot_2->xAxis->setTickVectorLabels(labels2);
         ui->plot_2->xAxis->setTickLabelRotation(60);
         ui->plot_2->xAxis->setSubTickCount(0);
         ui->plot_2->xAxis->setTickLength(0, 8);
         ui->plot_2->xAxis->grid()->setVisible(true);
         ui->plot_2->xAxis->setRange(-1, time);
         ui->plot_2->xAxis->setLabel("Time (day)");

         // prepare y axis:
         ui->plot_2->yAxis->setRange(-1, 101);
         ui->plot_2->yAxis->setPadding(5); // a bit more space to the left border
         ui->plot_2->yAxis->setLabel("Crowd Percentage on Location 1 (%)");
         //ui->plot_2->yAxis->grid()->setSubGridVisible(true);
         ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

/***************************Spot 2 *******************************/
         ui->plot_3->addGraph();
         pen.setColor(QColor(qSin(1*1+1.2)*80+80, qSin(1*0.3+0)*80+80, qSin(1*0.3+1.5)*80+80));
         ui->plot_3->graph()->setPen(pen);
        //ui->plot_2->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
         ui->plot_3->graph()->setLineStyle((QCPGraph::LineStyle)1);
         ui->plot_3->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
         // generate data:
         QVector<double> y2(j);
         for (int i = 0; i < b2.size(); i++){
              y2[i]=b2.at(i);
          }
          ui->plot_3->graph()->setData(x, y2);
          //ui->plot_2->graph()->rescaleAxes(true);
          ui->plot_3->xAxis->setAutoTicks(false);
          ui->plot_3->xAxis->setAutoTickLabels(false);
          ui->plot_3->xAxis->setTickVector(x);
          ui->plot_3->xAxis->setTickVectorLabels(labels2);
          ui->plot_3->xAxis->setTickLabelRotation(60);
          ui->plot_3->xAxis->setSubTickCount(0);
          ui->plot_3->xAxis->setTickLength(0, 8);
          ui->plot_3->xAxis->grid()->setVisible(true);
          ui->plot_3->xAxis->setRange(-1, time);
          ui->plot_3->xAxis->setLabel("Time (day)");

          // prepare y axis:
          ui->plot_3->yAxis->setRange(-1, 101);
          ui->plot_3->yAxis->setPadding(5); // a bit more space to the left border
          ui->plot_3->yAxis->setLabel("Crowd Percentage on Location 2 (%)");
          //ui->plot_3->yAxis->grid()->setSubGridVisible(true);
          ui->plot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

/********************************SPot 3***************************************/
         ui->plot_4->addGraph();
          pen.setColor(QColor(qSin(1*1+1.2)*80+80, qSin(1*0.3+0)*80+80, qSin(1*0.3+1.5)*80+80));
          ui->plot_4->graph()->setPen(pen);
         //ui->plot_2->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
          ui->plot_4->graph()->setLineStyle((QCPGraph::LineStyle)1);
          ui->plot_4->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
          // generate data:
          QVector<double> y3(j);
          for (int i = 0; i < b3.size(); i++){
               y3[i]=b3.at(i);
           }
           ui->plot_4->graph()->setData(x, y3);
           //ui->plot_2->graph()->rescaleAxes(true);
           ui->plot_4->xAxis->setAutoTicks(false);
           ui->plot_4->xAxis->setAutoTickLabels(false);
           ui->plot_4->xAxis->setTickVector(x);
           ui->plot_4->xAxis->setTickVectorLabels(labels2);
           ui->plot_4->xAxis->setTickLabelRotation(60);
           ui->plot_4->xAxis->setSubTickCount(0);
           ui->plot_4->xAxis->setTickLength(0, 8);
           ui->plot_4->xAxis->grid()->setVisible(true);
           ui->plot_4->xAxis->setRange(-1, time);
           ui->plot_4->xAxis->setLabel("Time (day)");

           // prepare y axis:
           ui->plot_4->yAxis->setRange(-1, 101);
           ui->plot_4->yAxis->setPadding(5); // a bit more space to the left border
           ui->plot_4->yAxis->setLabel("Crowd Percentage on Location 3 (%)");
           //ui->plot_3->yAxis->grid()->setSubGridVisible(true);
           ui->plot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

/********************************SPot 4***************************************/
           ui->plot_5->addGraph();
           pen.setColor(QColor(qSin(1*1+1.2)*80+80, qSin(1*0.3+0)*80+80, qSin(1*0.3+1.5)*80+80));
           ui->plot_5->graph()->setPen(pen);
          //ui->plot_2->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
           ui->plot_5->graph()->setLineStyle((QCPGraph::LineStyle)1);
           ui->plot_5->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
           // generate data:
           QVector<double> y4(j);
           for (int i = 0; i < b4.size(); i++){
                y4[i]=b4.at(i);
            }
            ui->plot_5->graph()->setData(x, y4);
            //ui->plot_2->graph()->rescaleAxes(true);
            ui->plot_5->xAxis->setAutoTicks(false);
            ui->plot_5->xAxis->setAutoTickLabels(false);
            ui->plot_5->xAxis->setTickVector(x);
            ui->plot_5->xAxis->setTickVectorLabels(labels2);
            ui->plot_5->xAxis->setTickLabelRotation(60);
            ui->plot_5->xAxis->setSubTickCount(0);
            ui->plot_5->xAxis->setTickLength(0, 8);
            ui->plot_5->xAxis->grid()->setVisible(true);
            ui->plot_5->xAxis->setRange(-1, time);
            ui->plot_5->xAxis->setLabel("Time (day)");

            // prepare y axis:
            ui->plot_5->yAxis->setRange(-1, 101);
            ui->plot_5->yAxis->setPadding(5); // a bit more space to the left border
            ui->plot_5->yAxis->setLabel("Crowd Percentage on Location 4 (%)");
            //ui->plot_3->yAxis->grid()->setSubGridVisible(true);
            ui->plot_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

/********************************SPot 5***************************************/
           ui->plot_6->addGraph();
            pen.setColor(QColor(qSin(1*1+1.2)*80+80, qSin(1*0.3+0)*80+80, qSin(1*0.3+1.5)*80+80));
            ui->plot_6->graph()->setPen(pen);
           //ui->plot_2->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
            ui->plot_6->graph()->setLineStyle((QCPGraph::LineStyle)1);
            ui->plot_6->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
            // generate data:
            QVector<double> y5(j);
            for (int i = 0; i < b5.size(); i++){
                 y5[i]=b5.at(i);
             }
             ui->plot_6->graph()->setData(x, y5);
             //ui->plot_2->graph()->rescaleAxes(true);
             ui->plot_6->xAxis->setAutoTicks(false);
             ui->plot_6->xAxis->setAutoTickLabels(false);
             ui->plot_6->xAxis->setTickVector(x);
             ui->plot_6->xAxis->setTickVectorLabels(labels2);
             ui->plot_6->xAxis->setTickLabelRotation(60);
             ui->plot_6->xAxis->setSubTickCount(0);
             ui->plot_6->xAxis->setTickLength(0, 8);
             ui->plot_6->xAxis->grid()->setVisible(true);
             ui->plot_6->xAxis->setRange(-1, time);
             ui->plot_6->xAxis->setLabel("Time (day)");

             // prepare y axis:
             ui->plot_6->yAxis->setRange(-1, 101);
             ui->plot_6->yAxis->setPadding(5); // a bit more space to the left border
             ui->plot_6->yAxis->setLabel("Crowd Percentage on Location 5 (%)");
             //ui->plot_3->yAxis->grid()->setSubGridVisible(true);
             ui->plot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

  // Note: we could have also just called customPlot->rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
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
          cursor.insertText("\nStrategy score:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot, width, height));
          break;
      case 1:
          cursor.insertText("\nPercentage of fishers at location 1 over time:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot_2, width, height));
          break;
      case 2:
          cursor.insertText("\nPercentage of fishers at location 2 over time:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot_3, width, height));
          break;
      case 3:
          cursor.insertText("\nPercentage of fishers at location 3 over time:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot_4, width, height));
          break;
      case 4:
          cursor.insertText("\nPercentage of fishers at location 4 over time:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot_5, width, height));
          break;
      case 5:
          cursor.insertText("\nPercentage of fishers at location 5 over time:" + QString(QChar::ObjectReplacementCharacter) + "\n", QCPDocumentObject::generatePlotFormat(ui->plot_6, width, height));
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


#ifndef graphview_H
#define graphview_H

//! \file graphview.h 
//! \brief provides a view that shows the collected graphs and allows them to be inserted into a report.

#include <QMainWindow>
#include <QTextDocument>
#include <QFileDialog>
#include <QWidget>
#include "qcpdocumentobject.h"

namespace Ui {
class Graphview;
}

//! \brief provides a view that shows the collected graphs and allows them to be inserted into a report.
//!
//! Graphview is intended to be used after the simulation has finished. It will accept data from
//! the simulation module defining plots and display them to the users. There is also a report view
//! on the left side that allows users to insert selected graphs to compile a final report.
class Graphview : public QMainWindow
{
  Q_OBJECT
  
public:
    //!
    //! \brief constructor for the Graphview class
    //!
  explicit Graphview(QWidget *parent = 0);
  ~Graphview();
  
    //! configures the plots
    //! \brief setupPlot
    //!
  void setupPlot();
  void printSettings(QString s);
  
private slots:
  void on_actionInsert_Plot_triggered();
  void on_actionSave_Document_triggered();
  
private:
  Ui::Graphview *ui;
};

#endif // graphview_H

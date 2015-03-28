#ifndef graphview_H
#define graphview_H

#include <QMainWindow>
#include <QTextDocument>
#include <QFileDialog>
#include <QWidget>
#include "qcpdocumentobject.h"

namespace Ui {
class Graphview;
}

//! provides a view that shows the colected graphs and allows them to be inserted into a report.
//!
//! Graphview is intended to be used after the simulation has finished. It will accept data from
//! the simulation module deffineing plots and display them to the users. There is also a report view
//! on the left side that allows users to insert selected graphs to compile a final report.
class Graphview : public QMainWindow
{
  Q_OBJECT
  
public:
    //!
    //! \brief Graphview::setupPlot
    //!
  explicit Graphview(QWidget *parent = 0);
  ~Graphview();
  
    //! configures the plots
    //! \brief setupPlot
    //!
  void setupPlot();
  
private slots:
  void on_actionInsert_Plot_triggered();
  void on_actionSave_Document_triggered();
  
private:
  Ui::Graphview *ui;
};

#endif // graphview_H

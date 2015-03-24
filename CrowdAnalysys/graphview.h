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

class Graphview : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit Graphview(QWidget *parent = 0);
  ~Graphview();
  
  void setupPlot();
  
private slots:
  void on_actionInsert_Plot_triggered();
  void on_actionSave_Document_triggered();
  
private:
  Ui::Graphview *ui;
};

#endif // graphview_H

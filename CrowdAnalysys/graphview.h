/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011, 2012, 2013, 2014 Emanuel Eichhammer               **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 27.12.14                                             **
**          Version: 1.3.0                                                **
****************************************************************************/

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

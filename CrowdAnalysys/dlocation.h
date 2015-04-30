#ifndef DLOCATION_H
#define DLOCATION_H
#include <QtWidgets>
#include <QVector>


class Dlocation : public QWidget
{
public:
    Dlocation(QWidget *parent);

    bool setPop(int number);
    int getPop(void);
    bool setCenter(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


};

#endif // DLOCATION_H

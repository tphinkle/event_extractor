#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include <QVector>
#include <QObject>

class QCustomPlot;
class QScrollBar;

class Data;
#include "cursor.h"

class Plot: public QObject
{

    Q_OBJECT

public:
    Plot();

    virtual ~Plot();

    void set_plotwidget(QCustomPlot* plotwidget);

    QCustomPlot* plotwidget();
    Cursor* cursor_1();
    Cursor* cursor_2();

    void Set_Up_Cursors();


    void set_xbar(QScrollBar* xbar);


    void set_ybar(QScrollBar* ybar);


    void set_data(Data* data);

    void Zoom_In_x();
    void Zoom_Out_x();

    void Zoom_In_y();
    void Zoom_Out_y();

    void Move_x();
    void Move_y();


    void xbar_Moved();
    void ybar_Moved();



private:
    QCustomPlot* plotwidget_;
    QScrollBar* xbar_;
    QScrollBar* ybar_;
    Cursor cursor_1_, cursor_2_;





    void Set_Up_Plot(Data* data);

    void Sync_xbar();

    void Sync_ybar();

    void set_xmin(Data* data);
    void set_xmax(Data* data);
    void set_ymin(Data* data);
    void set_ymax(Data* data);



    double xmin_;
    double xmax_;
    double ymin_;
    double ymax_;


    double dx_coeff_;
    double xzoom_coeff_;

    double dy_coeff_;
    double yzoom_coeff_;

    int xbar_pos_;
    int xbar_max_;

    int ybar_pos_;
    int ybar_max_;


public slots:
    void Clicked(QMouseEvent* click);

};

#endif // PLOT_H

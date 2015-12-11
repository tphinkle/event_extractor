#include "plot.h"

#include <iostream>

#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"

#include "data.h"

#include <QScrollBar>

Plot::Plot()
{

    xzoom_coeff_ = 1.5;
    dx_coeff_ = 0.1;

    yzoom_coeff_ = 1.5;
    dy_coeff_ = 0.1;


}

Plot::~Plot()
{


}

void Plot::Set_Up_Cursors()
{
    QCPItemLine* hcursor_1 = new QCPItemLine(plotwidget_);
    QCPItemLine* vcursor_1 = new QCPItemLine(plotwidget_);
    QCPItemLine* hcursor_2 = new QCPItemLine(plotwidget_);
    QCPItemLine* vcursor_2 = new QCPItemLine(plotwidget_);
    QTextEdit* textboxwidget_1 = new QTextEdit(plotwidget_);
    QTextEdit* textboxwidget_2 = new QTextEdit(plotwidget_);

    cursor_1_.set_buddycursor(&cursor_2_);
    cursor_2_.set_buddycursor(&cursor_1_);

    cursor_1_.set_cursorwidgets(hcursor_1, vcursor_1, textboxwidget_1);
    cursor_2_.set_cursorwidgets(hcursor_2, vcursor_2, textboxwidget_2);



    return;
}

Cursor* Plot::cursor_1()
{
    return &cursor_1_;
}

Cursor* Plot::cursor_2()
{
    return &cursor_2_;
}


void Plot::set_data(Data* data)
{

    plotwidget_->graph(0)->setData(data->datax(), data->datay());

    Set_Up_Plot(data);

    xbar_max_ = 99;
    xbar_pos_ = 0;

    ybar_max_ = 99;
    ybar_pos_ = 0;

    Sync_xbar();
    Sync_ybar();

    plotwidget_->replot();

    return;
}

void Plot::Set_Up_Plot(Data* data)
{
    set_xmin(data);
    set_xmax(data);
    set_ymin(data);
    set_ymax(data);
    return;
}

void Plot::set_xmin(Data* data)
{
    xmin_ = 0;
    return;
}

void Plot::set_xmax(Data* data)
{
    xmax_ = data->duration();
    return;
}

void Plot::set_ymin(Data* data)
{

    ymin_ = data->ymin();
    std::cerr << "ymin_ = " << ymin_ << "\n";
    return;
}

void Plot::set_ymax(Data* data)
{

    ymax_ = data->ymax();
    std::cerr << "ymax_ = " << ymax_ << "\n";
    return;
}





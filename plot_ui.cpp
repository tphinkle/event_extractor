#include "plot.h"

#include <iostream>

#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"

#include "data.h"
//#include "cursor.h"

#include <QScrollBar>

void Plot::set_plotwidget(QCustomPlot* plotwidget)
{
    plotwidget_ = plotwidget;
    plotwidget_->addGraph();
    //plotwidget_->setInteractions();
    plotwidget_->setNoAntialiasingOnDrag(true);


    Set_Up_Cursors();



    return;
}

void Plot::set_xbar(QScrollBar* xbar)
{
    xbar_ = xbar;


    return;
}

void Plot::set_ybar(QScrollBar* ybar)
{
    ybar_ = ybar;


    return;
}


void Plot::Zoom_In_x()
{

    double old_xlower = plotwidget_->xAxis->range().lower;

    double old_xupper = plotwidget_->xAxis->range().upper;

    double old_xrange = old_xupper - old_xlower;

    double new_xrange = (1.0/xzoom_coeff_) * old_xrange;

    double dx_ = dx_coeff_ * new_xrange;

    xbar_max_ = static_cast<int>((xmax_ - xmin_)/dx_) - 1;

    xbar_pos_ = static_cast<int>(xbar_max_*(old_xlower/(xmax_ - xmin_)));



    Sync_xbar();


    return;
}

void Plot::Zoom_Out_x()
{


    double old_xlower = plotwidget_->xAxis->range().lower;

    double old_xupper = plotwidget_->xAxis->range().upper;

    double old_xrange = old_xupper - old_xlower;

    double new_xrange = xzoom_coeff_ * old_xrange;


    double dx_ = dx_coeff_ * new_xrange;

    xbar_max_ = static_cast<int>((xmax_ - xmin_)/dx_) - 1;

    xbar_pos_ = static_cast<int>(xbar_max_*(old_xlower/(xmax_ - xmin_)));

    std::cerr << "!!xbar_max = " << xbar_max_ << "\n";
    std::cerr << "!!xbar_pos = " << xbar_pos_ << "\n";

    if(new_xrange > xmax_ - xmin_)
    {
        new_xrange = xmax_ - xmin_;
        dx_ = 0;
        xbar_max_ = 0;
        xbar_pos_ = 0;
    }


    Sync_xbar();


    return;
}

void Plot::Zoom_In_y()
{

    double old_ylower = plotwidget_->yAxis->range().lower;

    double old_yupper = plotwidget_->yAxis->range().upper;

    double old_yrange = old_yupper - old_ylower;

    double new_yrange = (1.0/yzoom_coeff_) * old_yrange;

    double dy_ = dy_coeff_ * new_yrange;

    ybar_max_ = static_cast<int>((ymax_ - ymin_)/dy_) - 1;

    ybar_pos_ = -1*(static_cast<int>(ybar_max_*(old_ylower/(ymax_ - ymin_))) - ybar_max_);


    Sync_ybar();


    return;
}

void Plot::Zoom_Out_y()
{

    double old_ylower = plotwidget_->yAxis->range().lower;

    double old_yupper = plotwidget_->yAxis->range().upper;

    double old_yrange = old_yupper - old_ylower;

    double new_yrange = yzoom_coeff_ * old_yrange;


    double dy_ = dy_coeff_ * new_yrange;

    ybar_max_ = static_cast<int>((ymax_ - ymin_)/dy_) - 1;

    ybar_pos_ = -1*(static_cast<int>(ybar_max_*(old_ylower/(ymax_ - ymin_))) - ybar_max_);

    if(new_yrange > ymax_ - ymin_)
    {
        new_yrange = ymax_ - ymin_;
        dy_ = 0;
        ybar_max_ = 0;
        ybar_pos_ = 0;
    }


    Sync_ybar();

    return;
}




void Plot::xbar_Moved()
{

    xbar_pos_ = xbar_->sliderPosition();

    std::cerr << "!xbar_pos = " << xbar_pos_ << "\n";
    double xlower = xbar_pos_*(xmax_ - xmin_)/xbar_max_;
    double xupper = xlower + 1/(dx_coeff_)*(xmax_ - xmin_)/xbar_max_;


    if(xbar_max_ == 0)
    {
        xlower = xmin_;
        xupper = xmax_;
    }

    std::cerr << "xbar_pos_ = " << xbar_pos_ << "\n";
    std::cerr << "xlower = " << xlower << "\n";
    std::cerr << "xupper = " << xupper << "\n";


    plotwidget_->xAxis->setRange(xlower, xupper);

    plotwidget_->replot();

    return;
}

void Plot::ybar_Moved()
{


    ybar_pos_ = ybar_->sliderPosition();


    double ylower = ymin_ + (ybar_max_ - ybar_pos_)*(ymax_ - ymin_)/ybar_max_;
    double yupper = ylower + 1/(dy_coeff_)*(ymax_ - ymin_)/ybar_max_;

    if(ybar_max_ == 0)
    {
        ylower = ymin_;
        yupper = ymax_;
    }

    std::cerr << "ybar_pos_ = " << ybar_pos_ << "\n";
    std::cerr << "ylower = " << ylower << "\n";
    std::cerr << "yupper = " << yupper << "\n";


    plotwidget_->yAxis->setRange(ylower, yupper);

    plotwidget_->replot();

    return;
}

void Plot::Sync_xbar()
{
    int old_xbar_pos = xbar_->sliderPosition();


    if(old_xbar_pos > xbar_max_)
    {
        xbar_->setSliderPosition(xbar_pos_);
        xbar_->setMaximum(xbar_max_);



    }
    else
    {
        xbar_->setMaximum(xbar_max_);
        xbar_->setSliderPosition(xbar_pos_);
    }



    //xbar_->setMaximum(xbar_max_);
    std::cerr << "?xbarpos = " << xbar_pos_ << "\n";
    //xbar_->setSliderPosition(xbar_pos_);
    //xbar_->setMaximum(xbar_max_);
    std::cerr << "??xbarpos = " << xbar_pos_ << "\n";

    if(xbar_pos_ == old_xbar_pos)
    {
        xbar_Moved();
    }

    return;
}

void Plot::Sync_ybar()
{
    int old_ybar_pos = ybar_->sliderPosition();
    ybar_->setMaximum(ybar_max_);
    ybar_->setSliderPosition(ybar_pos_);

    if(ybar_pos_ == old_ybar_pos)
    {
        ybar_Moved();
    }

    return;
}

void Plot::Clicked(QMouseEvent* click)
{

    double x = plotwidget_->xAxis->pixelToCoord(click->pos().x());

    double x_lowerbound = plotwidget_->graph(0)->data()->lowerBound(x).value().key;
    std::cerr << "x_lowerbound = " << x_lowerbound << "\n";

    double y = plotwidget_->graph(0)->data()->value(x_lowerbound).value;
    std::cerr << "y = " << y << "\n";

    double window_x = click->pos().x();
    double window_y = click->pos().y();

    double xrange = plotwidget_->xAxis->range().upper - plotwidget_->xAxis->range().lower;




    if(click->button() == Qt::LeftButton)
    {
        cursor_1_.Move(window_x, window_y, x_lowerbound, y, xrange);
    }

    else if(click->button() == Qt::RightButton)
    {
        cursor_2_.Move(window_x, window_y, x_lowerbound, y, xrange);
    }

    return;
}

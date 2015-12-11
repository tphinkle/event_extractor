#include "cursor.h"
#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"    //QCustomPlot header files
#include <iostream>


Cursor::Cursor( )
{
    pen_.setWidth(2);
    hcursorwidget_width_coeff_ = 0.05;
    textboxwidget_window_ypos_ = 0;
    textboxwidget_window_width_ = 150;
    textboxwidget_window_height_ = 90;
    xpos_ = 0;
    ypos_ = 0;

}

Cursor::~Cursor()
{
    delete[] hcursorwidget_;
    delete[] vcursorwidget_;
    delete[] textboxwidget_;

}

void Cursor::Move(int window_xpos, int window_ypos, double xpos, double ypos, double xrange)
{
    if(visible_ == false)
    {
        set_visible(true);
    }

    if(xpos_ != xpos || visible_ == false)
    {
        window_xpos_ = window_xpos;
        window_ypos_ = window_ypos;

        xpos_ = xpos;
        ypos_ = ypos;

        double hcursorwidget_width_ = hcursorwidget_width_coeff_*xrange;

        hcursorwidget_->start->setCoords(xpos_ - hcursorwidget_width_/2, ypos_);
        hcursorwidget_->end->setCoords(xpos_ + hcursorwidget_width_/2, ypos_);

        vcursorwidget_->start->setCoords(xpos_, QCPRange::minRange);
        vcursorwidget_->end->setCoords(xpos_, QCPRange::maxRange);

        Move_TextBoxWidget();
    }

    else
    {
        set_visible(false);
    }

    return;
}

void Cursor::Move_TextBoxWidget()
{
    textboxwidget_->setAlignment(Qt::AlignCenter);

    int x = window_xpos_ - static_cast<int>(textboxwidget_window_width_/2.0);

    if(abs(window_xpos_ - buddycursor_->window_xpos()) >= textboxwidget_window_width_)
    {
        textboxwidget_->setGeometry(x, textboxwidget_window_ypos_, textboxwidget_window_width_, textboxwidget_window_height_);
    }



    else
    {
        Append_Delta();
    }

    QString line1 = "t = " + QString::number(xpos_) + " s\n";
    QString line2 = "I = " + QString::number(ypos_) + " pA\n";
    QString line3;
    QString line4;

    if(x > buddycursor_->window_xpos() - static_cast<int>(textboxwidget_window_width_/2.0))
    {
        line3 = "delta_t = " + QString::number(xpos_ - buddycursor_->xpos_) + "\n";
        line4 = "delta_I = " + QString::number(ypos_ - buddycursor_->ypos_);
    }
    else
    {
        buddycursor_->Append_Delta();
        line3 = "\n";
        line4 = "";
    }






    textboxwidget_->setText(line1 + line2 + line3 + line4);

    return;
}

void Cursor::Append_Delta()
{
    QString line1 = "t = " + QString::number(xpos_) + " s\n";
    QString line2 = "I = " + QString::number(ypos_) + " pA\n";
    QString line3 = "delta_t = " + QString::number(xpos_ - buddycursor_->xpos()) + "\n";
    QString line4 = "delta_I = " + QString::number(ypos_ - buddycursor_->ypos());

    textboxwidget_->setText(line1 + line2 + line3 + line4);

    return;
}





void Cursor::set_cursorwidgets(QCPItemLine* hcursorwidget, QCPItemLine* vcursorwidget, QTextEdit* textboxwidget)
{

    hcursorwidget_ = hcursorwidget;
    vcursorwidget_ = vcursorwidget;
    textboxwidget_ = textboxwidget;

    set_visible(false);
    textboxwidget_->setGeometry(window_xpos_, textboxwidget_window_ypos_, textboxwidget_window_width_, textboxwidget_window_height_);


    return;
}

QPen Cursor::pen()
{
    return pen_;
}

void Cursor::set_visible(bool visible)
{
    visible_ = visible;

    if(visible_)
    {
        std::cerr << "visible!\n";
    }
    else
    {
        std::cerr << "invisible!\n";
    }

    hcursorwidget_->setVisible(visible);
    vcursorwidget_->setVisible(visible);
    textboxwidget_->setVisible(visible);
    return;
}


void Cursor::set_pos(double xpos, double ypos)
{
    xpos_ = xpos;
    ypos_ = ypos;

    return;
}

void Cursor::set_dashed(bool dashed)
{
    if( dashed == true )
    {
        pen_.setStyle(Qt::DotLine);
    }
    else
    {
        pen_.setStyle(Qt::SolidLine);
    }
    return;
}

void Cursor::set_window_xpos(double xclick, double xwindow)
{
    window_xpos_ = xclick + xwindow;
    return;
}



void Cursor::set_color(QColor color)
{
    color_ = color;
    pen_.setColor(color_);
    return;
}

QColor Cursor::color()
{
    return color_;
}

double Cursor::xpos()
{
    return xpos_;
}

double Cursor::ypos()
{
    return ypos_;
}

void Cursor::set_xpos(double xpos)
{
    xpos_ = xpos;
    return;
}

int Cursor::window_xpos()
{
    return window_xpos_;
}

void Cursor::set_buddycursor(Cursor* buddycursor)
{
    buddycursor_ = buddycursor;
    return;
}



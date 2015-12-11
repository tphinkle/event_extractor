#include "data.h"


#include <iostream>

Data::Data()
{

    //datax_.reserve(sizeof(double)*60*60*20000);
    //datay_.reserve(sizeof(double)*60*60*20000);
    datax_.resize(0);
    datay_.resize(0);
    dataloaded_ = false;


}

Data::~Data()
{
}

bool Data::dataloaded()
{
    return dataloaded_;
}

void Data::set_dataloaded(bool dataloaded)
{
    dataloaded_ = dataloaded;
    return;
}

QVector<double>& Data::datax()
{
    return datax_;
}

void Data::set_datax(QVector<double>& datax)
{
    datax_ = datax;
    return;
}

void Data::set_datax()
{

    for(int i = 0; i < length_; i++)
    {
        datax_.push_back(i*period_);
    }

    return;
}

QVector<double>& Data::datay()
{
    return datay_;
}

void Data::set_datay(QVector<double>& datay)
{
    datay_ = datay;
    return;
}


int Data::frequency()
{
    return frequency_;
}


void Data::set_frequency(int frequency)
{
    frequency_ = frequency;
    return;
}

double Data::period()
{
    return period_;
}

void Data::set_period(double period)
{
    period_ = period;
    set_frequency(static_cast<int>(1.0/period_));
    return;
}

double Data::duration()
{
    return duration_;
}

void Data::set_duration(double duration)
{
    duration_ = duration;
    return;
}

void Data::set_duration()
{
    duration_ = datay_.size()*period_;
    return;
}

int Data::length()
{
    return length_;
}


void Data::set_length(int length)
{
    length_ = length;
    return;
}

void Data::set_length()
{

    length_ = datay_.size();
    return;
}

double Data::ymin()
{
    return ymin_;
}

void Data::set_ymin(double ymin)
{
    ymin_ = ymin;
    return;
}

double Data::ymax()
{
    return ymax_;
}

void Data::set_ymax(double ymax)
{
    ymax_ = ymax;
    return;
}

void Data::Add_Datay_Element(double yelement)
{
    datay_.push_back(yelement);



    if(datay_.size() == 1)
    {
        ymin_ = yelement;
        ymax_ = yelement;
    }

    else
    {
        if(yelement < ymin_)
        {
            ymin_ = yelement;
        }

        else if(yelement > ymax_)
        {
            ymax_ = yelement;
        }
    }

    return;
}



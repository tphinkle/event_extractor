#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>

#include "fileloader.h"
#include "data.h"
#include "plot.h"
#include "eventsaver.h"
#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetUp_Buttons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoadFile_Button_clicked()
{
    FileLoader::Load_File(data_);
    this->setWindowTitle(FileLoader::loaded_file_name());
    plot_->set_data(data_);

    QString file_prefix = this->windowTitle().split("/").last().split(".").first();

    eventsaver_->set_file_prefix(file_prefix);

    return;
}

QCustomPlot* MainWindow::plotwidget()
{
    return ui->Plot_Widget;
}

void MainWindow::set_data(Data* data)
{
    data_ = data;
    return;
}

void MainWindow::set_eventsaver(EventSaver* eventsaver)
{
    eventsaver_ = eventsaver;
    return;
}

void MainWindow::set_plot(Plot* plot)
{
    plot_ = plot;
    plot_->set_plotwidget(ui->Plot_Widget);
    plot_->set_xbar(ui->x_Bar);
    plot_->set_ybar(ui->y_Bar);

    connect(ui->Plot_Widget, SIGNAL(mousePress(QMouseEvent*)), plot_, SLOT(Clicked(QMouseEvent*)));



    return;
}

void MainWindow::on_Zoom_In_x_Button_clicked()
{
    plot_->Zoom_In_x();
    return;
}

void MainWindow::on_Zoom_Out_x_Button_clicked()
{
    plot_->Zoom_Out_x();
    return;
}

void MainWindow::on_Zoom_In_y_Button_clicked()
{
    plot_->Zoom_In_y();
    return;
}


void MainWindow::on_Zoom_Out_y_Button_clicked()
{
    plot_->Zoom_Out_y();
    return;
}




void MainWindow::on_y_Bar_sliderMoved(int position)
{
    //plot_->Move_ybar();

    return;
}

void MainWindow::on_x_Bar_sliderMoved(int position)
{
    //plot_->Move_xbar();

    return;
}

void MainWindow::on_x_Bar_valueChanged(int value)
{
    plot_->xbar_Moved();
    return;
}

void MainWindow::on_y_Bar_valueChanged(int value)
{
    plot_->ybar_Moved();
    return;
}

void MainWindow::on_SaveEvent_Button_clicked()
{
    eventsaver_->Save_Event();
    return;
}

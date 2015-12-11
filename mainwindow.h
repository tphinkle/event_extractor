#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Plot;
class Data;
class QCustomPlot;
class EventSaver;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void set_plot(Plot* plot);
    void set_data(Data* data);
    void set_eventsaver(EventSaver* eventsaver);

    Plot* plot();
    Data* data();
    EventSaver* eventsaver();

    QCustomPlot* plotwidget();

private slots:
    void on_LoadFile_Button_clicked();

    void on_Zoom_In_x_Button_clicked();

    void on_Zoom_Out_x_Button_clicked();

    void on_Zoom_In_y_Button_clicked();

    void on_Zoom_Out_y_Button_clicked();

    void on_y_Bar_sliderMoved(int position);

    void on_x_Bar_sliderMoved(int position);

    void on_x_Bar_valueChanged(int value);

    void on_y_Bar_valueChanged(int value);

    void on_SaveEvent_Button_clicked();

private:
    Ui::MainWindow *ui;

    void SetUp_Buttons();
    void SetUp_LoadFile_Button();
    void SetUp_SaveEvent_Button();
    void SetUp_Plot();

    Plot* plot_;
    Data* data_;
    EventSaver* eventsaver_;


};

#endif // MAINWINDOW_H

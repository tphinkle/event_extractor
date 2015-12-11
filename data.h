#ifndef DATA_H
#define DATA_H

#include <vector>
#include <QVector>

class Data
{
public:
    Data();
    ~Data();

    void Set_Up_Cursors();

    QVector<double>& datax();
    void set_datax(QVector<double>& datax);
    void set_datax();

    QVector<double>& datay();
    void set_datay(QVector<double>& datay);

    bool dataloaded();
    void set_dataloaded(bool dataloaded);

    int frequency();
    void set_frequency(int frequency);

    double period();
    void set_period(double period);

    double duration();
    void set_duration(double duration);
    void set_duration();

    int length();
    void set_length(int length);
    void set_length();

    double ymin();
    void set_ymin(double ymin);

    double ymax();
    void set_ymax(double ymax);

    void Add_Datay_Element(double yelement);





private:

    bool dataloaded_;

    QVector<double> datax_;
    QVector<double> datay_;

    int frequency_;
    double period_;
    double duration_;
    int length_;

    double ymin_;
    double ymax_;
};

#endif // DATA_H

#ifndef CURSOR_H
#define CURSOR_H

#include <QLineEdit>
#include <QColor>

#ifndef CURSOR_H
#define CURSOR_H

#endif // CURSOR_H



class QCPItemLine;
class QTextEdit;



class Cursor
{
public:

    Cursor();
    ~Cursor();


    void Move(int window_xpos, int window_ypos, double xpos, double ypos, double xrange);

    void set_pos(double xpos, double ypos);

    double xpos();
    double ypos();

    void set_xpos(double xpos);
    void set_ypos(double ypos);

    void set_visible(bool visible);

    QPen pen();
    void set_window_xpos(double xclick, double xwindow);
    int window_xpos();

    void set_cursorwidgets(QCPItemLine* hcursorwidget, QCPItemLine* vcursorwidget, QTextEdit* textboxwidget);



    void set_color(QColor color_);
    QColor color();
    void set_dashed(bool dashed);

    void set_buddycursor(Cursor* buddycursor);

private:

    void Move_TextBoxWidget();
    void Append_Delta();


    QCPItemLine* hcursorwidget_;
    QCPItemLine* vcursorwidget_;
    QTextEdit* textboxwidget_;
    Cursor* buddycursor_;

    double xpos_;
    double ypos_;

    int window_xpos_;
    int window_ypos_;

    int textboxwidget_window_ypos_;
    int textboxwidget_window_width_;
    int textboxwidget_window_height_;

    bool offscreen_;
    QPen pen_;

    QColor color_;

    double hcursorwidget_width_coeff_;

    bool visible_;


};

#endif // CURSOR_H

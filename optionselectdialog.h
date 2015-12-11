#ifndef OPTIONSELECTDIALOG_H
#define OPTIONSELECTDIALOG_H

#include <vector>

#include <QMainWindow>
#include <QDialog>
#include <QFileDialog>

class QString;
class QStringList;
class QPushButton;

namespace Ui{
    class OptionSelectDialog;
}

class OptionSelectDialog: public QDialog
{
    Q_OBJECT

public:
    //OptionSelectDialog();
    explicit OptionSelectDialog(QWidget *parent = 0, QStringList optionlist = QStringList());
    ~OptionSelectDialog();

    int selectedoptionint();



private slots:
    void ButtonPressed();

private:
    void SetUpDialog();
    void CreateButtons();

    int dialog_width_;
    int dialog_height_;
    int button_count_;



    QStringList optionlist_;
    std::vector<QPushButton*> buttonlist_;
    int selectedoptionint_;

    Ui::OptionSelectDialog *ui;


};

#endif // OPTIONSELECTDIALOG_H

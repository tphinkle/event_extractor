#include "optionselectdialog.h"
#include "ui_optionselectdialog.h"

#include <iostream>

#include <QPushButton>

OptionSelectDialog::OptionSelectDialog(QWidget *parent, QStringList optionlist) :
    QDialog(parent), optionlist_(optionlist),
    ui(new Ui::OptionSelectDialog)
{
    SetUpDialog();
    CreateButtons();
}

OptionSelectDialog::~OptionSelectDialog()
{
    delete ui;
}

void OptionSelectDialog::SetUpDialog()
{
    ui->setupUi(this);
    setWindowTitle("Option select dialog");
    dialog_width_ = 820;
    dialog_height_ = 512;
    this->setGeometry(0,0, dialog_width_, dialog_height_);
    return;
}

void OptionSelectDialog::CreateButtons()
{
    int x, y, w, h;



    button_count_ = optionlist_.size();

    y = static_cast<int>(dialog_height_/2.0);
    w = static_cast<int>(dialog_width_/(button_count_*2.0));
    h = w;

    for(int i = 0; i < button_count_; i++)
    {
        buttonlist_.push_back(new QPushButton(this));
        buttonlist_[i]->setText(optionlist_[i]);

        x = static_cast<int>(1.0*dialog_width_/button_count_ *i);

        buttonlist_[i]->setGeometry(x, y, w, h);

        connect(buttonlist_[i], SIGNAL(clicked()), this, SLOT(ButtonPressed()));
    }



    return;
}


void OptionSelectDialog::ButtonPressed()
{
    for(int i = 0; i < button_count_ ; i++ )
    {
        if( buttonlist_[i] == QObject::sender() )
        {
            selectedoptionint_ = i;
            this->close();
        }
    }

    return;
}


int OptionSelectDialog::selectedoptionint()
{
    return selectedoptionint_;
}



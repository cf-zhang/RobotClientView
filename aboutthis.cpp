#include "aboutthis.h"

AboutThis::AboutThis(QWidget *parent) : QMessageBox(parent)
{

    setWindowTitle("custon box");

    QPushButton *oKBtn = addButton(QMessageBox::Ok);
    setText("this is a message box");
    setIconPixmap(QPixmap(":/image/settings.png"));

//    if(customBox.clickedButton()==oKBtn)
//        label->setText("custom message box / oKBtn");


}
AboutThis::~AboutThis(){

}


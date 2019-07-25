#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showState(){
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=200);
}

void Widget::changeMoney(int n){
    if(money + n >= 0){
        money += n;
        ui->lcdNumber->display(QString::number(money));
    }else {
        QMessageBox msg;
        msg.information(nullptr,"Error","Insert More Money!");
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    showState();
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    showState();
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    showState();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    showState();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    showState();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    showState();
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    showState();
}

void Widget::on_pushButton_clicked()
{
    char buffer[100];
    int coin500 = money/500;
    int coin100 = (money-coin500*500)/100;
    int coin50 = (money-coin500*500-coin100*100)/50;
    int coin10 = (money-coin500*500-coin100*100-coin50*50)/10;
    sprintf(buffer,"500 : %d\n100 : %d\n50 : %d\n10 : %d",coin500,coin100,coin50,coin10);

    changeMoney(-Widget::money);
    QMessageBox msg;
    msg.information(nullptr,"Return",buffer);
}

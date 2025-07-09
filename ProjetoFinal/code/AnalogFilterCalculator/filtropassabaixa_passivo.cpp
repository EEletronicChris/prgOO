#include "FiltroPassaBaixa_passivo.h"

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent, float fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(720, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(700, 440);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaBaixa_passivo.png");
    imageLabel->setPixmap(imagem);
}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RC()
{
    imageLabel->show();

}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RL() {}

void FiltroPassaBaixa_passivo::components_calc()
{
    //pg. 569 Sadiku
    capacitor_value = 0.000001;
    capacitor_label = new QLabel(this);
    floatToText = QString::number(capacitor_value, 'g', 15);
    capacitor_label->setText(floatToText + " F");   // Qlabel imprime float
    capacitor_label->resize(60, 30);
    capacitor_label->move(535, 185);
    capacitor_label->show();


    resistor_value = 1/(capacitor_value * central_frequency * 2 * PI);
    resistor_label = new QLabel(this);
    floatToText = QString::number(resistor_value, 'g', 2);
    resistor_label->setText(floatToText + " Ω");   // Qlabel imprime float
    resistor_label->resize(80, 30);
    resistor_label->move(250, 5);
    resistor_label->show();

    draw_low_pass_passive_RC();


}

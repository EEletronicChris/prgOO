#include "FiltroPassaAlta_ativo.h"

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent, double ganho, double fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;
    // Botão reiniciar
    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(1120, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    // Ajustes imagem
    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(1100, 374);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaAlta_ativo.png");
    imageLabel->setPixmap(imagem);

}

void FiltroPassaAlta_ativo::draw_high_pass_active()
{
    imageLabel->show();

    resistor_i_label->resize(60, 25);
    resistor_i_label->move(245, 165);
    resistor_i_label->show();

    resistor_f_label->resize(60, 22);
    resistor_f_label->move(730, 65);
    resistor_f_label->show();

    capacitor_label->resize(80, 30);
    capacitor_label->move(450, 190);
    capacitor_label->show();
}

void FiltroPassaAlta_ativo::components_calc()
{
    resistor_i_value = 1000;                        //1000 ohms provisório
    resistor_i_label = new QLabel(this);
    doubleToText = QString::number(resistor_i_value, 'g', 2);
    resistor_i_label->setText(doubleToText + " Ω");    // Qlabel imprime double

    resistor_f_value = gain_value * resistor_i_value;
    resistor_f_label = new QLabel(this);
    doubleToText = QString::number(resistor_f_value, 'g', 2);
    resistor_f_label->setText(doubleToText + " Ω");

    capacitor_value = 1/(2* PI * resistor_i_value * central_frequency );
    capacitor_label = new QLabel(this);
    doubleToText = QString::number(capacitor_value, 'g', 2);
    capacitor_label->setText(doubleToText + " F");

    draw_high_pass_active();
}


#include "filtropassafaixa_ativo.h"

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent, double ganho, double fInf, double fSup) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << "ganho: " << gain_value;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(1140, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(1120, 337);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaFaixa_ativo.png");
    imageLabel->setPixmap(imagem);
}

void FiltroPassaFaixa_ativo::draw_pass_band_active()
{
    imageLabel->show();

    resistor_R1_label->resize(80, 22);
    resistor_R1_label->move(115, 138);
    resistor_R1_label->show();

    resistor_R2_label->resize(80, 22);
    resistor_R2_label->move(255, 90);
    resistor_R2_label->show();

    resistor_R3_label->resize(80, 22);
    resistor_R3_label->move(390, 165);
    resistor_R3_label->show();

    resistor_R4_label->resize(80, 22);
    resistor_R4_label->move(625, 110);
    resistor_R4_label->show();

    capacitor_1_label->resize(60, 22);
    capacitor_1_label->move(255, 5);
    capacitor_1_label->show();

    capacitor_2_label->resize(60, 22);
    capacitor_2_label->move(490, 150);
    capacitor_2_label->show();

    resistor_i_label->resize(60, 22);
    resistor_i_label->move(770, 183);
    resistor_i_label->show();

    resistor_f_label->resize(60, 22);
    resistor_f_label->move(923, 135);
    resistor_f_label->show();
}

void FiltroPassaFaixa_ativo::components_calc()
{
    resistor_R_value = 10000;            // 10k ohms provisório
    resistor_R1_label = new QLabel(this);
    resistor_R2_label = new QLabel(this);
    resistor_R3_label = new QLabel(this);
    resistor_R4_label = new QLabel(this);
    doubleToText = QString::number(resistor_R_value, 'g', 2);
    resistor_R1_label->setText(doubleToText + " Ω");
    resistor_R2_label->setText(doubleToText + " Ω");
    resistor_R3_label->setText(doubleToText + " Ω");
    resistor_R4_label->setText(doubleToText + " Ω");

    capacitor_1_value = 1/(resistor_R_value * upper_cut_frequency * 2 * PI);
    capacitor_1_label = new QLabel(this);
    doubleToText = QString::number(capacitor_1_value, 'g', 2);
    capacitor_1_label->setText(doubleToText + " F");   // Qlabel imprime double

    capacitor_2_value = 1/(resistor_R_value * lower_cut_frequency * 2 * PI);
    capacitor_2_label = new QLabel(this);
    doubleToText = QString::number(capacitor_2_value, 'g', 2);
    capacitor_2_label->setText(doubleToText + " F");   // Qlabel imprime double

    resistor_i_value = 20000;                        //20k ohms provisório
    resistor_i_label = new QLabel(this);
    doubleToText = QString::number(resistor_i_value, 'g', 2);
    resistor_i_label->setText(doubleToText + " Ω");

    resistor_f_value = (gain_value * resistor_i_value * (upper_cut_frequency + lower_cut_frequency))/upper_cut_frequency ;
    resistor_f_label = new QLabel(this);
    doubleToText = QString::number(resistor_f_value, 'g', 2);
    resistor_f_label->setText(doubleToText + " Ω");

    draw_pass_band_active();
}

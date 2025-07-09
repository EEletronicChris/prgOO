#include "filtropassafaixa_passivo.h"

FiltroPassaFaixa_passivo::FiltroPassaFaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaFaixa_passivo::FiltroPassaFaixa_passivo(QWidget *parent, float fInf, float fSup) : FiltroPassivo(parent) {

    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(974, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(954, 440);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaFaixa_passivo_serie.png");
    imageLabel->setPixmap(imagem);
}

void FiltroPassaFaixa_passivo::draw_pass_band_passive_S() {
    imageLabel->show();
}

void FiltroPassaFaixa_passivo::draw_pass_band_passive_P() {}

void FiltroPassaFaixa_passivo::components_calc() {
    draw_pass_band_passive_S();

    double B = (upper_cut_frequency - lower_cut_frequency)* 2 * PI;
    double Wo = (B/2) + lower_cut_frequency;

    inductor_value = 0.001;          // 1mH provisório
    inductor_label = new QLabel(this);
    floatToText = QString::number(inductor_value, 'g', 15);
    inductor_label->setText(floatToText + " H");   // Qlabel imprime float
    inductor_label->resize(80, 30);
    inductor_label->move(260, 15);
    inductor_label->show();

    resistor_value = inductor_value * B;
    resistor_label = new QLabel(this);
    floatToText = QString::number(resistor_value, 'g', 2);
    resistor_label->setText(floatToText + " Ω");   // Qlabel imprime float
    resistor_label->resize(60, 30);
    resistor_label->move(650, 220);
    resistor_label->show();

    capacitor_value = 1/(Wo * Wo * inductor_value);
    capacitor_label = new QLabel(this);
    floatToText = QString::number(capacitor_value, 'g', 2);
    capacitor_label->setText(floatToText + " F");   // Qlabel imprime float
    capacitor_label->resize(80, 30);
    capacitor_label->move(500, 120);
    capacitor_label->show();
}

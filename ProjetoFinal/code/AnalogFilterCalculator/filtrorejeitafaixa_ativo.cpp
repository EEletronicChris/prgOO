#include "filtrorejeitafaixa_ativo.h"

FiltroRejeitaFaixa_ativo::FiltroRejeitaFaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroRejeitaFaixa_ativo::FiltroRejeitaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency <<  "ganho: " << gain_value;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(910, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(890, 512);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroRejeitaFaixa_ativo.png");
    imageLabel->setPixmap(imagem);
}

void FiltroRejeitaFaixa_ativo::draw_reject_band_active()
{
    imageLabel->show();

    resistor_R1_label->resize(80, 22);
    resistor_R1_label->move(218, 138);
    resistor_R1_label->show();

    resistor_R2_label->resize(80, 22);
    resistor_R2_label->move(358, 90);
    resistor_R2_label->show();

    resistor_R3_label->resize(80, 22);
    resistor_R3_label->move(118, 365);
    resistor_R3_label->show();

    resistor_R4_label->resize(80, 22);
    resistor_R4_label->move(358, 310);
    resistor_R4_label->show();

    capacitor_1_label->resize(60, 22);
    capacitor_1_label->move(358, 5);
    capacitor_1_label->show();

    capacitor_2_label->resize(60, 22);
    capacitor_2_label->move(220, 345);
    capacitor_2_label->show();

    resistor_i1_label->resize(60, 22);
    resistor_i1_label->move(495, 163);
    resistor_i1_label->show();

    resistor_i2_label->resize(60, 22);
    resistor_i2_label->move(502, 383);
    resistor_i2_label->show();

    resistor_f_label->resize(60, 22);
    resistor_f_label->move(696, 215);
    resistor_f_label->show();
}

void FiltroRejeitaFaixa_ativo::components_calc()
{
    resistor_R_value = 10000;            // 10k ohms provisório
    resistor_R1_label = new QLabel(this);
    resistor_R2_label = new QLabel(this);
    resistor_R3_label = new QLabel(this);
    resistor_R4_label = new QLabel(this);
    floatToText = QString::number(resistor_R_value, 'g', 2);
    resistor_R1_label->setText(floatToText + " Ω");
    resistor_R2_label->setText(floatToText + " Ω");
    resistor_R3_label->setText(floatToText + " Ω");
    resistor_R4_label->setText(floatToText + " Ω");

    capacitor_1_value = 1/(resistor_R_value * upper_cut_frequency * 2 * PI);
    capacitor_1_label = new QLabel(this);
    floatToText = QString::number(capacitor_1_value, 'g', 2);
    capacitor_1_label->setText(floatToText + " F");   // Qlabel imprime float

    capacitor_2_value = 1/(resistor_R_value * lower_cut_frequency * 2 * PI);
    capacitor_2_label = new QLabel(this);
    floatToText = QString::number(capacitor_2_value, 'g', 2);
    capacitor_2_label->setText(floatToText + " F");   // Qlabel imprime float

    resistor_i_value = 20000;                        //20k ohms provisório
    resistor_i1_label = new QLabel(this);
    resistor_i2_label = new QLabel(this);
    floatToText = QString::number(resistor_i_value, 'g', 2);
    resistor_i1_label->setText(floatToText + " Ω");
    resistor_i2_label->setText(floatToText + " Ω");

    resistor_f_value = gain_value * resistor_i_value;
    resistor_f_label = new QLabel(this);
    floatToText = QString::number(resistor_f_value, 'g', 2);
    resistor_f_label->setText(floatToText + " Ω");

    draw_reject_band_active();
}


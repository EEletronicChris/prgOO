#include "filtrorejeitafaixa_passivo.h"
#include "graficofiltropassivo.h"

FiltroRejeitaFaixa_passivo::FiltroRejeitaFaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroRejeitaFaixa_passivo::FiltroRejeitaFaixa_passivo(QWidget *parent, double fInf, double fSup) : FiltroPassivo(parent) {

    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(724, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    botaoGrafico = new QPushButton("Gerar gráfico", this);
    botaoGrafico->setStyleSheet("background-color: #1C1C1C");
    botaoGrafico->resize(100, 30);
    botaoGrafico->move(724, 50);
    botaoGrafico->show();
    connect(botaoGrafico, &QPushButton::clicked,this,&FiltroRejeitaFaixa_passivo::prepare_graph);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(704, 510);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroRejeitaFaixa_passivo_serie.png");
    imageLabel->setPixmap(imagem);
}

void FiltroRejeitaFaixa_passivo::draw_reject_band_passive_P() {}

void FiltroRejeitaFaixa_passivo::draw_reject_band_passive_S()
{
    imageLabel->show();

    inductor_label->resize(80, 30);
    inductor_label->move(530, 380);
    inductor_label->show();

    resistor_label->resize(80, 30);
    resistor_label->move(250, 5);
    resistor_label->show();

    capacitor_label->resize(80, 30);
    capacitor_label->move(550, 190);
    capacitor_label->show();
}

void FiltroRejeitaFaixa_passivo::components_calc()
{
    double B = (upper_cut_frequency - lower_cut_frequency)* 2 * PI;
    double Wo = (B/2) + lower_cut_frequency;

    inductor_value = 0.000001;          // 1uH provisório
    inductor_label = new QLabel(this);
    doubleToText = QString::number(inductor_value, 'g', 15);
    inductor_label->setText(doubleToText + " H");   // Qlabel imprime double

    resistor_value = inductor_value * B;
    resistor_label = new QLabel(this);
    doubleToText = QString::number(resistor_value, 'g', 2);
    resistor_label->setText(doubleToText + " Ω");   // Qlabel imprime double

    capacitor_value = 1/(Wo * Wo * inductor_value);
    capacitor_label = new QLabel(this);
    doubleToText = QString::number(capacitor_value, 'g', 2);
    capacitor_label->setText(doubleToText + " F");   // Qlabel imprime double

    draw_reject_band_passive_S();
}

void FiltroRejeitaFaixa_passivo::prepare_graph()
{
    GraficoFiltroPassivo *grafico = new GraficoFiltroPassivo(this, resistor_value, capacitor_value, inductor_value);
    grafico->draw_graph_rejeita_faixa();
    grafico->show();
}

#include "FiltroPassaBaixa_passivo.h"

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent, double fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(720, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    botaoGrafico = new QPushButton("Gerar gráfico", this);
    botaoGrafico->setStyleSheet("background-color: #1C1C1C");
    botaoGrafico->resize(100, 30);
    botaoGrafico->move(720, 50);
    botaoGrafico->show();
    connect(botaoGrafico, &QPushButton::clicked,this,&FiltroPassaBaixa_passivo::prepare_graph);

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

    capacitor_label->resize(60, 30);
    capacitor_label->move(535, 185);
    capacitor_label->show();

    resistor_label->resize(80, 30);
    resistor_label->move(250, 5);
    resistor_label->show();
}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RL() {}

void FiltroPassaBaixa_passivo::components_calc()
{
    //pg. 569 Sadiku
    capacitor_value = 0.000001;
    capacitor_label = new QLabel(this);
    doubleToText = QString::number(capacitor_value, 'g', 15);
    capacitor_label->setText(doubleToText + " F");   // Qlabel imprime double

    resistor_value = 1/(capacitor_value * central_frequency * 2 * PI);
    resistor_label = new QLabel(this);
    doubleToText = QString::number(resistor_value, 'g', 2);
    resistor_label->setText(doubleToText + " Ω");   // Qlabel imprime double

    draw_low_pass_passive_RC();
}

void FiltroPassaBaixa_passivo::prepare_graph()
{
    GraficoFiltroPassivo *grafico = new GraficoFiltroPassivo(this, resistor_value, capacitor_value, 0.0);
    grafico->draw_graph_passa_baixa();
    grafico->show();
}

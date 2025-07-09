#include "FiltroPassaBaixa_ativo.h"

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->setStyleSheet("background-color: #1C1C1C");
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(924, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(904, 580);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaBaixa_ativo.png");
    imageLabel->setPixmap(imagem);


}

void FiltroPassaBaixa_ativo::draw_low_pass_active() {
    imageLabel->show();
}

void FiltroPassaBaixa_ativo::components_calc()
{
    resistor_i_value = 1000;                        //1000 ohms provisório
    resistor_i_label = new QLabel(this);
    floatToText = QString::number(resistor_i_value, 'g', 2);
    resistor_i_label->setText(floatToText + " Ω");    // Qlabel imprime float
    resistor_i_label->resize(60, 30);
    resistor_i_label->move(240, 280);
    resistor_i_label->show();

    resistor_f_value = gain_value * resistor_i_value;
    resistor_f_label = new QLabel(this);
    floatToText = QString::number(resistor_f_value, 'g', 2);
    resistor_f_label->setText(floatToText + " Ω");    // Qlabel imprime float
    resistor_f_label->resize(60, 22);
    resistor_f_label->move(535, 60);
    resistor_f_label->show();

    capacitor_value = 1/(2* PI * resistor_f_value * central_frequency );
    capacitor_label = new QLabel(this);
    floatToText = QString::number(capacitor_value, 'g', 2);
    capacitor_label->setText(floatToText + " F");   // Qlabel imprime float
    capacitor_label->resize(80, 30);
    capacitor_label->move(535, 180);
    capacitor_label->show();

    draw_low_pass_active();
}

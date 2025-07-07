#include "FiltroPassaAlta_ativo.h"

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;

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

    resistor_i_label = new QLabel(this);
    floatToText = QString::number(resistor_i_value);
    resistor_i_label->setText(floatToText + " Ω");   // Qlabel imprime float
    resistor_i_label->resize(40, 30);
    resistor_i_label->move(10, 10);
    resistor_i_label->show();
}

void FiltroPassaAlta_ativo::components_calc() {
    draw_high_pass_active();
}

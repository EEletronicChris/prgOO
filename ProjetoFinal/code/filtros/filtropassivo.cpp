#include "filtropassivo.h"

FiltroPassivo::FiltroPassivo() : freqInfEdit(nullptr), freqSupEdit(nullptr), freqInfLabel(nullptr), freqSupLabel(nullptr) {}

void FiltroPassivo::esconderCampos() {
    if (freqInfLabel) freqInfLabel->hide();
    if (freqInfEdit) freqInfEdit->hide();
    if (freqSupLabel) freqSupLabel->hide();
    if (freqSupEdit) freqSupEdit->hide();
}

void FiltroPassivo::atualizarCampos(QWidget *parent, const QString &tipoFiltro) {
    esconderCampos();

    if (!tipoFiltro.contains("passa-faixa") && !tipoFiltro.contains("rejeita-faixa")) return;

    if (!freqInfLabel) {
        freqInfLabel = new QLabel(parent);
        freqInfEdit = new QLineEdit(parent);
        freqSupLabel = new QLabel(parent);
        freqSupEdit = new QLineEdit(parent);
    }

    freqInfLabel->setText("Frequência de corte inferior:");
    freqSupLabel->setText("Frequência de corte superior:");

    freqInfLabel->move(10, 170);
    freqInfLabel->resize(180, 25);
    freqInfEdit->move(200, 170);
    freqInfEdit->resize(100, 25);

    freqSupLabel->move(10, 210);
    freqSupLabel->resize(180, 25);
    freqSupEdit->move(200, 210);
    freqSupEdit->resize(100, 25);

    freqInfLabel->show();
    freqInfEdit->show();
    freqSupLabel->show();
    freqSupEdit->show();
}

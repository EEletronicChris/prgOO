#include "filtroativo.h"

FiltroAtivo::FiltroAtivo() : ganhoEdit(nullptr), ganhoLabel(nullptr), frequenciaEdit(nullptr), frequenciaLabel(nullptr) {}

void FiltroAtivo::esconderCampos() {
    if (ganhoLabel) ganhoLabel->hide();
    if (ganhoEdit) ganhoEdit->hide();
    if (frequenciaLabel) frequenciaLabel->hide();
    if (frequenciaEdit) frequenciaEdit->hide();
}

void FiltroAtivo::atualizarCampos(QWidget *parent, const QString &tipoFiltro) {
    esconderCampos();

    if (!tipoFiltro.startsWith("Ativo")) return;

    if (!ganhoLabel) {
        ganhoLabel = new QLabel(parent);
        ganhoEdit = new QLineEdit(parent);
        frequenciaLabel = new QLabel(parent);
        frequenciaEdit = new QLineEdit(parent);
    }

    ganhoLabel->setText("Ganho:");
    ganhoLabel->move(10, 90);
    ganhoLabel->resize(180, 25);
    ganhoEdit->move(200, 90);
    ganhoEdit->resize(100, 25);
    ganhoLabel->show();
    ganhoEdit->show();

    if (tipoFiltro == "Ativo passa-baixa") {
        frequenciaLabel->setText("Frequência de corte inferior:");
    } else if (tipoFiltro == "Ativo passa-alta") {
        frequenciaLabel->setText("Frequência de corte superior:");
    } else {
        frequenciaLabel->setText("Frequência:");
    }

    frequenciaLabel->move(10, 130);
    frequenciaLabel->resize(180, 25);
    frequenciaEdit->move(200, 130);
    frequenciaEdit->resize(100, 25);
    frequenciaLabel->show();
    frequenciaEdit->show();
}

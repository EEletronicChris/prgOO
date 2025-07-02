#include "filtroativo.h"

FiltroAtivo::FiltroAtivo(QObject *parent) : QObject(parent),
    ganhoEdit(nullptr), frequenciaEdit(nullptr),
    ganhoLabel(nullptr), frequenciaLabel(nullptr) {}

void FiltroAtivo::limparCampos(QVBoxLayout *layout) {
    if (ganhoLabel) layout->removeWidget(ganhoLabel);
    if (ganhoEdit) layout->removeWidget(ganhoEdit);
    if (frequenciaLabel) layout->removeWidget(frequenciaLabel);
    if (frequenciaEdit) layout->removeWidget(frequenciaEdit);

    delete ganhoLabel;
    delete ganhoEdit;
    delete frequenciaLabel;
    delete frequenciaEdit;

    ganhoLabel = nullptr;
    ganhoEdit = nullptr;
    frequenciaLabel = nullptr;
    frequenciaEdit = nullptr;
}

void FiltroAtivo::atualizarCampos(QVBoxLayout *layout, const QString &tipoFiltro) {
    limparCampos(layout);

    if (tipoFiltro == "Ativo passa-baixa" || tipoFiltro == "Ativo passa-alta") {
        ganhoLabel = new QLabel("Ganho:");
        ganhoEdit = new QLineEdit();

        frequenciaLabel = new QLabel(
            tipoFiltro == "Ativo passa-baixa" ?
                "Frequência de corte inferior:" :
                "Frequência de corte superior:"
            );
        frequenciaEdit = new QLineEdit();

        layout->addWidget(ganhoLabel);
        layout->addWidget(ganhoEdit);
        layout->addWidget(frequenciaLabel);
        layout->addWidget(frequenciaEdit);
    }
}

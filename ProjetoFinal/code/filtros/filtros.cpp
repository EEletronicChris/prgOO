#include "filtros.h"

Filtros::Filtros(QObject *parent) : QObject(parent) {}

void Filtros::carregarPassivos(QComboBox *comboBox) {
    comboBox->clear();
    comboBox->addItems({
        "Passivo passa-baixa",
        "Passivo passa-alta",
        "Passivo passa-faixa",
        "Passivo rejeita-faixa"
    });
}

void Filtros::carregarAtivos(QComboBox *comboBox) {
    comboBox->clear();
    comboBox->addItems({
        "Ativo passa-baixa",
        "Ativo passa-alta",
        "Ativo passa-faixa",
        "Ativo rejeita-faixa"
    });
}

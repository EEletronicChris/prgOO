#include "filtros.h"

Filtros::Filtros(QObject *parent) : QObject(parent) {}

void Filtros::carregarPassivos(QComboBox *comboBox) {
    comboBox->clear();
    comboBox->addItems({"Passivo passa-baixa", "Passivo passa-alta"});
}

void Filtros::carregarAtivos(QComboBox *comboBox) {
    comboBox->clear();
    comboBox->addItems({"Ativo passa-baixa", "Ativo passa-alta"});
}

#include "filtropassivo.h"

FiltroPassivo::FiltroPassivo() : Filtros(), freqInfEdit(nullptr), freqSupEdit(nullptr), freqInfLabel(nullptr), freqSupLabel(nullptr),freqCenEdit(nullptr), freqCenLabel(nullptr) {}


void FiltroPassivo::atualizarCampos(QWidget *parent, const QString &tipoFiltro) {
    // Esconde Widgets se existem
    if (freqInfLabel != nullptr){
        freqInfLabel->hide();
    }
    if (freqInfEdit != nullptr){
        freqInfEdit->hide();
    }
    if (freqSupLabel != nullptr){
        freqSupLabel->hide();
    }
    if (freqSupEdit != nullptr){
        freqSupEdit->hide();
    }
    if (freqCenLabel != nullptr){
        freqCenLabel->hide();
    }
    if (freqCenEdit != nullptr){
        freqCenEdit->hide();
    }

    if(tipoFiltro.contains("passa-baixa") || tipoFiltro.contains("passa-alta")){
        freqCenLabel = new QLabel(parent);
        freqCenEdit = new QLineEdit(parent);

        freqCenLabel->setText("Frequência de corte:");
        freqCenLabel->resize(180,25);
        freqCenLabel->move(10,80);
        freqCenEdit->resize(100,25);
        freqCenEdit->move(200,80);

        freqCenLabel->show();
        freqCenEdit->show();
    }

    if(tipoFiltro.contains("passa-faixa") || tipoFiltro.contains("rejeita-faixa")){
        freqInfLabel = new QLabel(parent);
        freqInfEdit = new QLineEdit(parent);
        freqSupLabel = new QLabel(parent);
        freqSupEdit = new QLineEdit(parent);

        freqInfLabel->setText("Frequência de corte inferior:");
        freqInfLabel->resize(180,25);
        freqInfLabel->move(10,80);
        freqInfEdit->resize(100,25);
        freqInfEdit->move(200,80);
        freqSupLabel->setText("Frequência de corte superior:");
        freqSupLabel->resize(180,25);
        freqSupLabel->move(10,140);
        freqSupEdit->resize(100,25);
        freqSupEdit->move(200,140);

        freqInfLabel->show();
        freqInfEdit->show();
        freqSupLabel->show();
        freqSupEdit->show();
    }
}

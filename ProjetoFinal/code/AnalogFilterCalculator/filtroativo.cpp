#include "filtroativo.h"
#include "filtropassaalta_ativo.h"
#include "filtropassabaixa_ativo.h"
#include "filtropassafaixa_ativo.h"
#include "filtrorejeitafaixa_ativo.h"

FiltroAtivo::FiltroAtivo(QWidget *parent) : Filtros(parent) {}

FiltroAtivo::FiltroAtivo(QWidget *parent, float ganho, float fInf, float fCent, float fSup) : Filtros(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;
    this->central_frequency = fCent;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << " central: " << central_frequency;
}

void FiltroAtivo::get_gain_value() {
    if (gain_value == 0){
        QMessageBox::about(this, "", "Valor de ganho considerado de 0 dB");
        qDebug() << "Chegou até aqui";
    }

}

void FiltroAtivo::filtro_plot_prepare_ativo()
{
    qDebug() << "Ganho2: " << gain_value;
    get_gain_value();
}

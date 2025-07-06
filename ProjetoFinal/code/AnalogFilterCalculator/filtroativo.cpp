#include "filtroativo.h"
#include "filtropassaalta_ativo.h"
#include "filtropassabaixa_ativo.h"
#include "filtropassafaixa_ativo.h"
#include "filtrorejeitafaixa_ativo.h"

FiltroAtivo::FiltroAtivo(QWidget *parent) : Filtros(parent) {}

FiltroAtivo::FiltroAtivo(QWidget *parent, float ganho, float fInf, float fCent, float fSup, QString tipo) : Filtros(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;
    this->central_frequency = fCent;
    this->filter_type = tipo;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << " central: " << central_frequency << "ganho: " << gain_value;
}

void FiltroAtivo::get_gain_value() {
    if (gain_value == 0){
        QMessageBox::about(this, "", "Valor de ganho considerado de 0 dB");
    }
}

void FiltroAtivo::filtro_plot_prepare_ativo()
{
    qDebug() << "tipo:  " << filter_type;
    get_gain_value();
}

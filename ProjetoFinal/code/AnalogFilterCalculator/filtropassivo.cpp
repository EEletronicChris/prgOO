#include "filtropassivo.h"
#include "filtropassaalta_passivo.h"
#include "filtropassabaixa_passivo.h"
#include "filtropassafaixa_passivo.h"
#include "filtrorejeitafaixa_passivo.h"

FiltroPassivo::FiltroPassivo(QWidget *parent) : Filtros(parent) {}

FiltroPassivo::FiltroPassivo(QWidget *parent, float fInf, float fCent, float fSup, QString tipo) : Filtros(parent) {
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;
    this->central_frequency = fCent;
    this->filter_type = tipo;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << " central: " << central_frequency << "ganho: " << gain_value;
}

void FiltroPassivo::get_component_preference() {}

void FiltroPassivo::get_choose_S_P() {}

void FiltroPassivo::filtro_plot_prepare_passivo()
{
    qDebug() << "tipo:  " << filter_type;

    if (filter_type == "Filtro Passivo Passa-baixa"){
        FiltroPassaBaixa_passivo *filt = new FiltroPassaBaixa_passivo(this, central_frequency);
        filt->components_calc();
        filt->show();
    }
    if (filter_type == "Filtro Passivo Passa-alta"){
        FiltroPassaAlta_passivo *filt = new FiltroPassaAlta_passivo(this, central_frequency);
        filt->components_calc();
        filt->show();
    }
    if (filter_type == "Filtro Passivo Rejeita-faixa"){
        FiltroRejeitaFaixa_passivo *filt = new FiltroRejeitaFaixa_passivo(this, lower_cut_frequency, upper_cut_frequency);
        filt->components_calc();
        filt->show();
    }
    if (filter_type == "Filtro Passivo Passa-faixa"){
        FiltroPassaFaixa_passivo *filt = new FiltroPassaFaixa_passivo(this, lower_cut_frequency, upper_cut_frequency);
        filt->components_calc();
        filt->show();
    }
}

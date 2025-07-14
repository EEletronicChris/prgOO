#include "filtroativo.h"
#include "filtropassaalta_ativo.h"
#include "filtropassabaixa_ativo.h"
#include "filtropassafaixa_ativo.h"
#include "filtrorejeitafaixa_ativo.h"

FiltroAtivo::FiltroAtivo(QWidget *parent) : Filtros(parent) {}

FiltroAtivo::FiltroAtivo(QWidget *parent, double ganho, double fInf, double fCent, double fSup, QString tipo) : Filtros(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;
    this->central_frequency = fCent;
    this->filter_type = tipo;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << " central: " << central_frequency << "ganho: " << gain_value;
}

void FiltroAtivo::get_gain_value()
{
    // Conversão para ganho em dB
}

void FiltroAtivo::filtro_plot_prepare_ativo()
{
    qDebug() << "tipo:  " << filter_type;
    get_gain_value();

    if (filter_type == "Filtro Ativo Passa-baixa"){
        FiltroPassaBaixa_ativo *filt = new FiltroPassaBaixa_ativo(this, gain_value, central_frequency);
        filt->show();
        filt->components_calc();
    }
    if (filter_type == "Filtro Ativo Passa-alta"){
        FiltroPassaAlta_ativo *filt = new FiltroPassaAlta_ativo(this, gain_value, central_frequency);
        filt->show();
        filt->components_calc();
    }
    if (filter_type == "Filtro Ativo Rejeita-faixa"){
        FiltroRejeitaFaixa_ativo *filt = new FiltroRejeitaFaixa_ativo(this, gain_value, lower_cut_frequency, upper_cut_frequency);
        filt->show();
        filt->components_calc();
    }
    if (filter_type == "Filtro Ativo Passa-faixa"){
        FiltroPassaFaixa_ativo *filt = new FiltroPassaFaixa_ativo(this, gain_value, lower_cut_frequency, upper_cut_frequency);
        filt->show();
        filt->components_calc();
    }
}

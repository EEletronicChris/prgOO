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

}

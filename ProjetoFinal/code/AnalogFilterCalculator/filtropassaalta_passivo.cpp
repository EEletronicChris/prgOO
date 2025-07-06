#include "FiltroPassaAlta_passivo.h"

FiltroPassaAlta_passivo::FiltroPassaAlta_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaAlta_passivo::FiltroPassaAlta_passivo(QWidget *parent, float fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() <<" central: " << central_frequency;
}


void FiltroPassaAlta_passivo::draw_high_pass_passive_RC() {}

void FiltroPassaAlta_passivo::draw_high_pass_passive_RL() {}

void FiltroPassaAlta_passivo::components_calc() {}


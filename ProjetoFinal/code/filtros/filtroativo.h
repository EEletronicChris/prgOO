#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QWidget>
#include "filtros.h"

class FiltroAtivo : public Filtros {
public:
    FiltroAtivo();
    void atualizarCampos(QWidget *parent, const QString &tipoFiltro);

private:
    QLineEdit *ganhoEdit;
    QLabel *ganhoLabel;

};

#endif // FILTROATIVO_H

#ifndef FILTROPASSABAIXA_ATIVO_H
#define FILTROPASSABAIXA_ATIVO_H

#include <QLabel>
#include <QString>
#include <QWidget>

class FiltroPassaBaixa_ativo {
public:
    FiltroPassaBaixa_ativo();
    void exibirImagem(QWidget *parent, const QString &tipoFiltro);

private:
    QLabel *imagemLabel;
};

#endif // FILTROPASSABAIXA_ATIVO_H

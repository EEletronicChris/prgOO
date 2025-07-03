#ifndef FILTROPASSABAIXA_PASSIVO_H
#define FILTROPASSABAIXA_PASSIVO_H

#include <QLabel>
#include <QString>
#include <QWidget>

class FiltroPassaBaixa_passivo {
public:
    FiltroPassaBaixa_passivo();
    void exibirImagem(QWidget *parent, const QString &tipoFiltro);

private:
    QLabel *imagemLabel;
};

#endif // FILTROPASSABAIXA_PASSIVO_H

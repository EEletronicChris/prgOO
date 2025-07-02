#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>

class FiltroAtivo : public QObject {
    Q_OBJECT

public:
    explicit FiltroAtivo(QObject *parent = nullptr);
    void atualizarCampos(QVBoxLayout *layout, const QString &tipoFiltro);

private:
    QLineEdit *ganhoEdit;
    QLineEdit *frequenciaEdit;
    QLabel *ganhoLabel;
    QLabel *frequenciaLabel;

    void limparCampos(QVBoxLayout *layout);
};

#endif // FILTROATIVO_H

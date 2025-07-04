#ifndef FILTROS_H
#define FILTROS_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

class Filtros : public QWidget {
    Q_OBJECT

public:
    explicit Filtros(QWidget *parent = nullptr);

    void get_filter_type();
    void get_lower_cut_frequency();
    void get_upper_cut_frequency();
    void get_central_frequency();
    void hide_all_edit();

protected:
    QString filter_type;
    float lower_cut_frequency;
    float upper_cut_frequency;
    float central_frequency;

private slots:
    void carregarFiltrosPassivos();
    void carregarFiltrosAtivos();
    void atualizarFiltroSelecionado();

private:
    QPushButton *botaoPassivo;
    QPushButton *botaoAtivo;
    QComboBox *filtersType_combo;
    QLineEdit *centralFreq_edit;
    QLabel *centralFreq_label;
    QLineEdit *supFreq_edit;
    QLabel *supFreq_label;
    QLineEdit *infFreq_edit;
    QLabel *infFreq_label;

};

#endif

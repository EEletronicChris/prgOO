#ifndef FILTROS_H
#define FILTROS_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

class Filtros : public QWidget {
    Q_OBJECT

public:
    explicit Filtros(QWidget *parent = nullptr);

    void get_lower_cut_frequency();
    void get_upper_cut_frequency();
    void get_central_frequency();
    void hide_all_edit();
    void get_gain_value();
    void show_both_freq_edit();
    void show_one_freq_edit();

protected:
    QString filter_type;
    float lower_cut_frequency;
    float upper_cut_frequency;
    float central_frequency;

private slots:
    void carregarFiltrosPassivos();
    void carregarFiltrosAtivos();
    void get_filter_type();
    void confirmarFiltroSelecionado();

private:
    // Botões da janela inicial
    QPushButton *botaoPassivo;
    QPushButton *botaoAtivo;
    QPushButton *botaoConfirmAll;
    // Seleção de filtros
    QComboBox *filtersType_combo;
    // Campos de preenchimento
    QLineEdit *centralFreq_edit;
    QLineEdit *supFreq_edit;
    QLineEdit *infFreq_edit;
    QLineEdit *gainValue_edit;
    // Campos de texto
    QLabel *centralFreq_label;
    QLabel *supFreq_label;
    QLabel *infFreq_label;
    QLabel *gainValue_label;

};

#endif

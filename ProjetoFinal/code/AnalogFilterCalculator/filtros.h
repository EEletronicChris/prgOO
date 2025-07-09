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
#include <QPixmap>

#define PI 3.14159265358979


class Filtros : public QWidget {
    Q_OBJECT

public:
    explicit Filtros(QWidget *parent = nullptr);

    void get_lower_cut_frequency();
    void get_upper_cut_frequency();
    void get_central_frequency();
    void hide_all_edit();
    void show_both_freq_edit();
    void show_one_freq_edit();
    void resetarInterface();


private:
    QString filter_type;
    QLineEdit *gainValue_edit;
    double lower_cut_frequency;
    double upper_cut_frequency;
    double central_frequency;
    double gain_value;

private slots:
    void carregarFiltrosPassivos();
    void carregarFiltrosAtivos();
    void get_filter_type();
    void confirmarFiltroSelecionado();

protected:
    // Botões da janela inicial
    QPushButton *botaoPassivo;
    QPushButton *botaoAtivo;
    QPushButton *botaoConfirmAll;
    // Seleção de filtros
    QComboBox *filtersType_combo;
private:
    // Campos de preenchimento
    QLineEdit *centralFreq_edit;
    QLineEdit *supFreq_edit;
    QLineEdit *infFreq_edit;
    // Campos de texto
    QLabel *centralFreq_label;
    QLabel *supFreq_label;
    QLabel *infFreq_label;
    QLabel *gainValue_label;
};

#endif

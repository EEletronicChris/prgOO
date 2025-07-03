#ifndef FILTROS_H
#define FILTROS_H

#include <QObject>
#include <QComboBox>
#include <QLabel>

class Filtros : public QObject {
    Q_OBJECT

public:
    explicit Filtros(QObject *parent = nullptr);
    void carregarPassivos(QComboBox *comboBox);
    void carregarAtivos(QComboBox *comboBox);

private:
    QLineEdit *freqInfEdit;
    QLineEdit *freqSupEdit;
    QLineEdit *freqCenEdit;

    QLabel *freqInfLabel;
    QLabel *freqSupLabel;
    QLabel *freqCenLabel;
};

#endif // FILTROS_H

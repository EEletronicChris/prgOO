#ifndef FILTROS_H
#define FILTROS_H

#include <QObject>
#include <QComboBox>

class Filtros : public QObject {
    Q_OBJECT

public:
    explicit Filtros(QObject *parent = nullptr);
    void carregarPassivos(QComboBox *comboBox);
    void carregarAtivos(QComboBox *comboBox);
};

#endif // FILTROS_H

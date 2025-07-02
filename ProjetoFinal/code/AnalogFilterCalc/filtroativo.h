#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include "analogfilters.h"
#include <QLineEdit>

class filtroAtivo : public analogFilters {
    Q_OBJECT

public:
    explicit filtroAtivo(QWidget *parent = nullptr);

private slots:
    void get_gain_value();

private:
    QLineEdit *gainInput;
};

#endif // FILTROATIVO_H

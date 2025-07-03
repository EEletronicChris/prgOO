#ifndef FILTROS_H
#define FILTROS_H

#include <QWidget>
#include <QString>

class Filtros : public QWidget {
    Q_OBJECT

public:
    explicit Filtros(QWidget *parent = nullptr);

    void get_filter_type();
    void get_lower_cut_frequency();
    void get_upper_cut_frequency();
    void get_central_frequency();

protected:
    QString filter_type;
    float lower_cut_frequency;
    float upper_cut_frequency;
    float central_frequency;
};

#endif

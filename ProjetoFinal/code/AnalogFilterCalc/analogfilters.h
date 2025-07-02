#ifndef ANALOGFILTERS_H
#define ANALOGFILTERS_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include "filtroativo.h"


class analogFilters : public QWidget {
    Q_OBJECT

public:
    explicit analogFilters(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void showComboPassives();
    void showComboActives();
    void saveFilterType();
    void reInitAplication();

private:
    QPushButton *passiveFilter_button;
    QPushButton *activeFilter_button;
    QPushButton *filterTypeConfirm_button;
    QPushButton *reInit_button;

    QComboBox   *filterType_combo;

    QString filterType_savings;

    void reposicionarElementos();
};

#endif // ANALOGFILTERS_H

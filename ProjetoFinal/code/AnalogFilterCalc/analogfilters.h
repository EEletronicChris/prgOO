#ifndef ANALOGFILTERS_H
#define ANALOGFILTERS_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>


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
    void showLowerCutFrequency_input();
    void showUpperCutFrequency_input();
    void showCentralCutFrequency_input();

private:
    QPushButton *passiveFilter_button;
    QPushButton *activeFilter_button;
    QPushButton *filterTypeConfirm_button;
    QPushButton *reInit_button;

    QComboBox   *filterType_combo;

    QString     filterType_savings;

    QLineEdit   *showLowerCutFrequency_LineEdit;
    QLineEdit   *showUpperCutFrequency_LineEdit;
    QLineEdit   *showCentralCutFrequency_LineEdit;

    void reposicionarElementos();
};

#endif // ANALOGFILTERS_H

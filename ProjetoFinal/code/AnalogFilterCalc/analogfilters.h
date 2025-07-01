#ifndef ANALOGFILTERS_H
#define ANALOGFILTERS_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>

class analogFilters : public QWidget {
    Q_OBJECT

public:
    explicit analogFilters(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void showComboPassives();
    void showComboActives();

private:
    QPushButton *passiveFilter_button;
    QPushButton *activeFilter_button;
    QComboBox *filterType_combo;

    void reposicionarElementos();
};

#endif // ANALOGFILTERS_H

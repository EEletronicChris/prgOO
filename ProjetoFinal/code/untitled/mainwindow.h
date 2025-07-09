#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace QtCharts {
class QChartView;
class QLineSeries;
}
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QtCharts::QChartView *chartView;
    void plotarResposta();
    QLineSeries *serie;
};

#endif // MAINWINDOW_H

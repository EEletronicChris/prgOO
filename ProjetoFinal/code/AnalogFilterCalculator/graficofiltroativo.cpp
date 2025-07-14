#include "graficofiltroativo.h"

#include <QtMath>
#include <complex>

using namespace std;

GraficoFiltroAtivo::GraficoFiltroAtivo(QWidget *parent) : QMainWindow(parent) {}

// Para passa faixa e rejeita faixa.
GraficoFiltroAtivo::GraficoFiltroAtivo(QWidget *parent, double resistor_R_value, double resistor_i_value,
                                       double resistor_f_value, double capacitor_value, double capacitor_1_value,
                                       double capacitor_2_value) : QMainWindow(parent)
{
    this->resistor_R_value = resistor_R_value;
    this->resistor_i_value = resistor_i_value;
    this->resistor_f_value = resistor_f_value;
    this->capacitor_value = capacitor_value;
    this->capacitor_1_value = capacitor_1_value;
    this->capacitor_2_value = capacitor_2_value;

    this->resize(1000, 650);

    chart = new QChart();

    serieMagnitude = new QLineSeries();

    chartView = new QChartView(chart);

    // Eixo x - Frequência em escala log
    eixoX = new QLogValueAxis;
    eixoX->setTitleText("Frequência (Hz)");
    eixoX->setLabelFormat("%.0e");
    eixoX->setBase(10);
    eixoX->setRange(0.1, 100000000);

    // Eixo y - ganho em dB | gráfico linear
    eixoY = new QValueAxis;
    eixoY->setTitleText("Ganho (dB)");
    eixoY->setRange(-50, 50);
    eixoY->setTickCount(9);
}

void GraficoFiltroAtivo::draw_graph_passa_alta()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000.0 / 0.1, double(i) / 5000);
        double omega = 2.0 * PI * freq;
        complex<double> num(0.0, omega * capacitor_value * resistor_f_value);
        complex<double> den(1.0, omega * capacitor_value * resistor_i_value);
        complex<double> H = num / den;
        double mag_dB = 20.0 * log10(abs(H));

        if (mag_dB < -50.0) mag_dB = -50.0;
        if (mag_dB > 50.0)  mag_dB = 50.0;

        serieMagnitude->append(freq, mag_dB);
    }

    chart->addSeries(serieMagnitude);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);

    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);

}

void GraficoFiltroAtivo::draw_graph_passa_baixa()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000.0 / 0.1, double(i) / 5000);
        double omega = 2.0 * PI * freq;
        complex<double> denom(1.0, omega * capacitor_value * resistor_f_value);
        complex<double> ganho = -resistor_f_value / resistor_i_value;
        complex<double> H = ganho / denom;
        double mag_dB = 20.0 * log10(abs(H));

        if (mag_dB < -50.0) mag_dB = -50.0;
        if (mag_dB > 50.0)  mag_dB = 50.0;

        serieMagnitude->append(freq, mag_dB);
    }

    chart->addSeries(serieMagnitude);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);

    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

void GraficoFiltroAtivo::draw_graph_passa_faixa()
{

}

void GraficoFiltroAtivo::draw_graph_rejeita_faixa()
{

}


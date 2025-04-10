/*
Definir uma classe que abstraia um círculo

Esta classe deve possuir métodos Privados para:

calcular a área do cı́rculo;
calcular a distância entre os centros de 2 cı́rculos;
calcular a circunferência do cı́rculo.
E métodos Públicos para:

definir o raio do cı́rculo, dado um número real;
aumentar o raio do cı́rculo, dado um percentual de aumento;
definir o centro do cı́rculo, dada uma posição (X,Y);
imprimir o valor do raio;
imprimir o centro do cı́rculo.
imprimir a área do cı́rculo.
Criar um programa principal para testar a classe.*/

#include <iostream>
#include <cmath>
#define pi 3.141592

using namespace std;

class Circulo{
private:
    // Variáveis
    float raio, c_x, c_y;
    //Método para cálculo da área
    float calc_area(){
        return pow(raio,2)*pi;
    }
    // Método para calcular a distância entre os centros de 2 cı́rculos
    float calc_d_2_pontos(Circulo &C2){
        return sqrt(pow((C2.c_x)-(c_x),2)+pow((C2.c_y)-(c_y),2));
    }
    // Método para calcular a circunferência do cı́rculo.
    float calc_circunferencia(){
        return 2 * pi * raio;
    }
public:
    // Método para definir o raio do circulo
    void set_raio (float raio){
        this->raio = raio;
    }
    // Método para aumentar o raio do cı́rculo, dado um percentual de aumento
    void increase_raio(float percentage){
        raio = raio * (1 + percentage);
    }
    // Método para definir o centro do cı́rculo, dada uma posição (X,Y)
    void set_centro(float x, float y){
        c_x = x;
        c_y = y;
    }
    // As funções seguintes são para imprimir raio, centro e área;
    void print_raio(){
        cout << "Raio: " << raio << endl;
    }
    void print_centro(){
        cout << "Centro: (" << c_x << ";" << c_y << ")" << endl;
    }
    void print_area(){
        cout << "area: " << calc_area() << endl;
    }
};

int main()
{
    Circulo C1, C2;
    float r1 = 7.4, r2 = 67.0;
    C1.set_raio(r1);
    C2.set_raio(r2);
    C1.set_centro(15.0,6.0);
    C2.set_centro(9.0,2.0);
    cout << "area normal de C1: ";
    C1.print_area();
    C1.increase_raio(0.5);
    cout << "area de C1 com raio = 150%: ";
    C1.print_area();
    cout <<  "centro de C1: "; 
    C1.print_centro();
    cout <<  "centro de C2: "; 
    C2.print_centro();

    return 0;
}
/*Implemente ua abstração de umm carro. O tanque de combustı́vel do carro armazena no máximo 50 litros de gasolina.
 O carro consome 15 km/litro. Deve ser possı́vel:

Abastecer o carro com uma certa quantidade de gasolina;
Mover o carro em uma determinada distância (medida em km);
Retornar a quantidade de combustı́vel e a distância total percorrida.
Elabore um programa para realizar o teste da sua abstração. Lembre-se de realizar um teste completo da sua interface.*/

#include <iostream>

using namespace std;

class Carro{
    float tanque, distancia_total = 0.0;
    int consumo = 15;
    
public:
    Carro(float gas){               // Carro deve inicialzar com uma quantidade de combustível definida
        if(gas > 0 && gas <= 50){
            tanque = gas;
        }else{tanque=0;}
    }       
    void abastecer(float gas){
        if (tanque + gas >= 50){
            tanque = 50;
        }
        else{
            tanque = tanque + gas;
        }
        cout << "Tanque abastecido, Volume total = " << tanque << "l" << endl;
    }
    void mover(float d){
        if (d <= tanque*consumo){
            tanque = tanque - d/consumo;
            distancia_total = distancia_total + d;
        }
        else{
            distancia_total = distancia_total + consumo/tanque;
            tanque = 0;
        }
        

        cout << "Distancia total percorrida: " << distancia_total << "km" << endl;
        cout << "Combustivel restante: " << tanque << "l" << endl;
    }


};

int main()
{
    Carro corolla(10);
    
    corolla.abastecer(2);
    corolla.mover(165);
    corolla.mover(50);
    corolla.abastecer(70);

    return 0;
}
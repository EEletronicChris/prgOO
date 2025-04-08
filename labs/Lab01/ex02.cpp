/*
Crie uma classe denominada Elevador para armazenar as informações de um elevador dentro de um prédio.
 A classe deve armazenar o andar atual (0 = térreo), total de andares no prédio, excluindo o térreo, 
capacidade do elevador, e quantas pessoas que estão presentes nele.

A classe deve implementar a seguinte interface:

Construtor: Deve receber como parâmetros: a capacidade do elevador e o total de andares no prédio 
(os elevadores sempre começam no térreo e vazios); **

entra: Acrescenta uma pessoa no elevador (só deve acrescentar se ainda houver espaço);

sai: para remover uma pessoa do elevador (só deve remover se houver alguém dentro dele);

sobe: para subir um andar (não deve subir se já estiver no último andar);

desce: para descer um andar (não deve descer se já estiver no térreo);

Métodos de acesso aos atributos: retorna o valor de cada atributo da classe. Crie um método para cada atributo
*/
#include <iostream>

using namespace std;

class Elevador{
private:
    int local_floor = 0, total_floors, capacity, passagers;
public:
    Elevador (int total_floors, int capacity);  //Construtor

    void entra(){
        if (passagers < capacity){
            passagers = passagers + 1;
            cout << "Ocupantes: " << passagers << endl;
        }
        else{
            cout << "Nao e possivel entrar" << endl;
        }
    }

    void sai(){
        if (passagers <= 0){
            cout << "Não há ninguem no elevador" << endl;
        }
        else{
            passagers = passagers - 1;
            cout << "Ocupantes: " << passagers << endl;
        }
    }

    void sobe(){
        if (local_floor >= total_floors){
            cout << "Não é possivel subir mais" << endl;
        }
        else{
            local_floor = local_floor + 1;
            cout << "Piso: " << local_floor << endl;
        }
    }
    
    void desce(){
        if (local_floor <= 0){
            cout << "Daqui pra frente só tem chao" << endl;
        }
        else{
            local_floor = local_floor - 1;
            cout << "Piso: " << local_floor << endl;
        }
    }

};

// O que o construtor faz
Elevador::Elevador (int tf, int c){
    total_floors = tf;
    capacity = c;
}

int main()
{
    Elevador arranhaceu(3,2);                 // Declara o objeto se utilizando do construtor

    arranhaceu.entra();
    
    arranhaceu.sai();
    
    arranhaceu.sobe();

    arranhaceu.desce();

}
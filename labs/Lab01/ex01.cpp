/*
Crie uma classe Pessoa para representar uma pessoa, com os atributos privados de nome,
idade e altura. Crie os métodos públicos necessários para acessar e modificar os atributos
desta classe e crie um método para imprimir os dados da pessoa.

Implemente um programa de teste que utilize toda a interface da classe criada.
*/

#include <iostream>
#include <string>

using namespace std;

class Pessoa{           //Definir uma classe pessoa
    private:
        std::string nome;
        int idade;
        float altura;
    public:
        void set_nia(string nome, int idade, float altura){
           this -> nome = nome;
           this -> idade = idade;
           this -> altura = altura; 
        }
        void show_nia(){
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
            cout << "Altura: " << altura << endl;
        }

};


int main()
{
    Pessoa christopher;     // Cria objeto christopher da classe Pessoa
    
    christopher.set_nia("Chris",23,172.8);
    christopher.show_nia();

    return 0;
}
#include "Funcionario.h"
#include "Registro.h"
#include "vector"
#include "string"


Funcionario::Funcionario(int id, string nome) : Usuario(id, nome) {
    this->id = id;
    this->nome = nome;
    registros = new vector<Registro* >();
}

Funcionario::Funcionario(int id, string nome, vector<Registro* >* registros) : Usuario(id, nome) {
    this->id = id;
    this->nome = nome;
    this->registros = registros;
}   


bool Usuario::entrar(Data *d){
    



}
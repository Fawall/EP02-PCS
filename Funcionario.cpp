#include "Funcionario.h"
#include "Registro.h"
#include "vector"
#include "string"


Funcionario::Funcionario(int id, string nome) {
    this->id = id;
    this->nome = nome;
    registros = new vector<Registro* >();
}
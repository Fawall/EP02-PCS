#include "Funcionario.h"
#include "Registro.h"
#include "vector"
#include "string"


using namespace std;

Funcionario::Funcionario(int id, string nome) : Usuario(id, nome) {
    this->id = id;
    this->nome = nome;
    this->registros = new vector<Registro* >();
}

Funcionario::Funcionario(int id, string nome, vector<Registro* >* registros) : Usuario(id, nome) {
    this->id = id;
    this->nome = nome;
    this->registros = registros;
}   

bool Funcionario::entrar(Data *d) {
    Registro* r = new Registro(d);

    if(registros->size() == 0) {
        registros->push_back(r);
        return true;
    }


}


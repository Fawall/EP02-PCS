#include "Funcionario.h"
#include "Entrada.h"
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
    Entrada* e = new Entrada(d);

    if(registros->size() == 0) {
        registros->push_back(e);
        return true;
    }

    (*registros)[registros->size() - 1]->getData()->getDia();

    if( (*registros)[registros->size() - 1] != e) {
        registros->push_back(e);
        return true;
    }

    int diferenca = d->diferenca((*registros)[registros->size() - 1]->getData());
    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Entrada*>(ultimoRegistro) != nullptr && diferenca < 0) {
        return false;
    } else {
        registros->push_back(e);
        return true;
    }
    return false;

}


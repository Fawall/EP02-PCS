#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"
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

    // int diferenca = d->diferenca((*registros)[registros->size() - 1]->getData());
    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Entrada*>(ultimoRegistro) != e && 
     d->diferenca((*registros)[registros->size() - 1]->getData()) > 0) {
        return false;
    } else {
        registros->push_back(e);
        return true;
    }
    return false;
}

bool Funcionario::sair(Data *d) {
    Saida* s = new Saida(d);

    if(registros->size() == 0) {
        registros->push_back(s);
        
        return false;
    }

    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Saida*>(ultimoRegistro) != s && 
     d->diferenca((*registros)[registros->size() - 1]->getData()) > 0) {
        return false;
    } else {
        registros->push_back(s);
        return true;
    }
    return false;
}


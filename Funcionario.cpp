#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"
#include "vector"
#include "string"
#include <iostream>

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

Funcionario::~Funcionario() {
    for(int i = 0; i < registros->size(); i++) {
        delete (*registros)[i];
    }
    delete registros;
}

bool Funcionario::entrar(Data *d) {
    Entrada* e = new Entrada(d);

    if(registros->size() == 0) {
        registros->push_back(e);
        return true;
    }

    // int diferenca = d->diferenca((*registros)[registros->size() - 1]->getData());
    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Entrada*>(ultimoRegistro) != nullptr && 
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
        
        return true;
    }

    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Saida*>(ultimoRegistro) != nullptr && 
     d->diferenca((*registros)[registros->size() - 1]->getData()) > 0) {
        return false;
    } else {
        registros->push_back(s);
        return true;
    }
    return false;
}

bool Funcionario::registrarEntradaManual(Data *d) {
    Entrada* e = new Entrada(d, true);

    if(registros->size() == 0) {
        registros->push_back(e);
        return true;
    }

    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Entrada*>(ultimoRegistro) != nullptr && 
     d->diferenca((*registros)[registros->size() - 1]->getData()) > 0) {
        return false;
    } else {
        registros->push_back(e);
        return true;
    }
    return false;
}

bool Funcionario::registrarSaidaManual(Data *d) {
    Saida* s = new Saida(d, true);

    if(registros->size() == 0) {
        registros->push_back(s);
        return true;
    }

    Registro* ultimoRegistro = (*registros)[registros->size() - 1];

    if(dynamic_cast<Saida*>(ultimoRegistro) != nullptr && 
     d->diferenca((*registros)[registros->size() - 1]->getData()) > 0) {
        return false;
    } else {
        registros->push_back(s);
        return true;
    }
    return false;
}

vector<Registro *> *Funcionario::getRegistros() {
    return registros;
}

int Funcionario::getHorasTrabalhadas(int mes, int ano) {
    if(registros->size() == 0) {
        return 0;
    }
    
    
    int horas = 0;

    for(int i = 0; i < registros->size(); i++) {
        Registro* r = (*registros)[i];
        if(r->getData()->getMes() == mes && r->getData()->getAno() == ano) {
            if(dynamic_cast<Entrada*>(r) != nullptr) {
                if(i + 1 < registros->size()) {
                    Registro* r2 = (*registros)[i + 1];
                    if(dynamic_cast<Saida*>(r2) != nullptr) {
                        horas += (r2->getData()->diferenca(r->getData()))/3600;
                    }
                }
            }
        }
    }
    return horas;
}



#include "Visitante.h"
#include <stdexcept>



Visitante::Visitante(int id, string nome, Data* inicio, Data* fim ) : Usuario(id, nome) {
    if(inicio == nullptr || inicio == 0 || fim == nullptr || fim == 0 || fim < inicio)
        throw new logic_error("Data invalida");


    this->id = id;
    this->nome = nome;
    this->inicio = inicio;
    this->fim = fim;
}

Visitante::~Visitante() {
    delete inicio;
    delete fim;
}

Data* Visitante::getDataInicio() {
    return inicio;
}

Data* Visitante::getDataFim() {
    return fim;
}

bool Visitante::entrar(Data *d) {

    if(d < getDataInicio() || d > getDataFim())
        return false;
    return true;
}

bool Visitante::sair(Data* d){
    if(d < getDataInicio() || d > getDataFim())
        return false;
    return true;
}

bool Visitante::registrarEntradaManual(Data *d){
    return false;
}

bool Visitante::registrarSaidaManual(Data *d){
    return false;
}

string Visitante::getNome() {
    return this->nome;
}

int Visitante::getId() {
    return this->id;
}

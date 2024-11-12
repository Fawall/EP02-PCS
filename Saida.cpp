#include "Saida.h"
#include <stdexcept>
#include <iostream>
#include "Registro.h"

using namespace std;

Saida::Saida(Data *d):Registro(d) { //jogo do construtor da entrada para o do registro, ent n preciso indicar o tipo da classe
    this->d = d;

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }
}

Saida::Saida(Data *d, bool manual):Registro(d, manual) {
    this->d = d;
    this->manual = manual;

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }
}

Saida::~Saida() {}
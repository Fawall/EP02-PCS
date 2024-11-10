#include "Entrada.h"
#include <stdexcept>
#include <iostream>
#include "Registro.h"
//#include "Data.h"

using namespace std;

Entrada::Entrada(Data *d):Registro(d) { //jogo do construtor da entrada para o do registro, ent n preciso indicar o tipo da classe
    this->d = d;

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }
}
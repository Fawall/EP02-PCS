#include "Registro.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Registro::Registro(Data *d, bool manual) {

    this->d = d;               //como eh um objeto, preciso inicializar ele
    this->manual = manual;      //diferente desse, que é um atributo

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }   
}

Registro::Registro(Data *d, bool manual) {

    this->d = d;           

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }
}

Registro::~Registro() {}

Data* Registro::getData() {
    return d;
}

bool Registro::isManual() {
    return manual;

}
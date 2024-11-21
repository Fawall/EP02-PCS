#include "Registro.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Registro::Registro(Data *d, bool manual) {

    this->d = d;               
    this->manual = manual;      

    if (d == nullptr) {
        throw new invalid_argument ("data invalida");
    }   
}

Registro::Registro(Data *d) {

    this->d = d;           
    this->manual = false;
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
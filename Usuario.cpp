#include "Usuario.h"
#include <stdexcept>

using namespace std;

Usuario::Usuario(int id, string nome) {
    this->id = id;
    this->nome = nome;
}

Usuario::~Usuario() {
}

string Usuario::getNome() {
    return this->nome;
}

int Usuario::getId() {
    return this->id;
}

bool Usuario::entrar(Data *d) {
    
}

bool Usuario::sair(Data *d) {
    
}

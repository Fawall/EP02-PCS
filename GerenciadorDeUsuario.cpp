#include "GerenciadorDeUsuario.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario() {
    this->usuarios = new vector<Usuario*>();
}


GerenciadorDeUsuario::GerenciadorDeUsuario(vector<Usuario*> usuarios) {
    this->usuarios = new vector<Usuario*>(usuarios);
}


void GerenciadorDeUsuario::adicionar(Usuario* u) {
    
    for(int i = 0; i < usuarios->size(); i++){
        if(usuarios->at(i)->getId() == u->getId())
            throw new invalid_argument("Usuario ja existe");
    }
    usuarios->push_back(u);
}

Usuario* GerenciadorDeUsuario::getUsuario(int id){
    for(int i = 0; i < usuarios->size(); i++){
        if(usuarios->at(i)->getId() == id)
            return usuarios->at(i);
    }
    return nullptr;
}

vector<Usuario*>* GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for(unsigned int i = 0; i < usuarios->size(); i++){
        delete usuarios->at(i);
    }
    delete usuarios;
}
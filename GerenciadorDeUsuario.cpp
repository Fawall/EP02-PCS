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


void GerenciadorDeUsuario::adicionarUsuario(Usuario* u) {
    vector<Usuario*>::iterator it = find_if(usuarios->begin(), usuarios->end(), [u](Usuario* usuario) { return usuario->getId() == u->getId(); });

    if(it != usuarios->end())
        throw new invalid_argument("Usuario ja existe");

    usuarios->push_back(u);
}

Usuario* GerenciadorDeUsuario::getUsuario(int id){
    vector<Usuario*>::iterator it = find_if(usuarios->begin(), usuarios->end(), [id](Usuario* usuario) { return usuario->getId() == id; });

    if(it == usuarios->end())
        return nullptr;

    return *it;
}

vector<Usuario*> GerenciadorDeUsuario::getUsuarios() {
    return *usuarios;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for(unsigned int i = 0; i < usuarios->size(); i++){
        delete usuarios->at(i);
    }
    delete usuarios;
}
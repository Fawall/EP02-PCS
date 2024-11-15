#include "Catraca.h"
#include "GerenciadorDeUsuario.h"


Catraca::Catraca(GerenciadorDeUsuario *g){
    this->g = g;
}

Catraca::~Catraca() {}

bool Catraca::entrar(int id, Data* d){
    if(g->getUsuarios().size() == 0 ){
        return false;
    }

    Usuario* u = g->getUsuario(id);
    if(u != nullptr)
        return u->entrar(d);
    return false;
}

bool Catraca::sair(int id, Data* d){
    if(g->getUsuarios().size() == 0 ){
        return false;
    }

    Usuario* u = g->getUsuario(id);
    if(u != nullptr)
        return u->sair(d);
    return false;
}

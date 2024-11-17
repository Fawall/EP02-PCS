#include "Catraca.h"
#include "GerenciadorDeUsuario.h"


Catraca::Catraca(GerenciadorDeUsuario *g){
    this->g = g;
}

Catraca::~Catraca() {}

bool Catraca::entrar(int id, Data* d){
    if(g->getUsuarios()->size() == 0 ){
        return false;
    }

    if(g->getUsuario(id) != nullptr && g->getUsuario(id)->entrar(d) == true)
        return g->getUsuario(id)->entrar(d);
    return false;
}

bool Catraca::sair(int id, Data* d){
    if(g->getUsuarios()->size() == 0 ){
        return false;
    }

    if(g->getUsuario(id) != nullptr && g->getUsuario(id)->sair(d) == true)
        return g->getUsuario(id)->sair(d);
    return false;
}

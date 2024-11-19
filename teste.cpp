void menu();
#include "Funcionario.h"
#include "GerenciadorDeUsuario.h"
#include "Catraca.h"
#include "Data.h"
#include <iostream>
#include <vector>
#include "PersistenciaDeUsuario.h"
#include "Aluno.h"

void testeDiferenca(){

    Funcionario* f = new Funcionario(1, "Joao");
    Data *d = new Data(10, 10, 10, 10, 10, 2010);

    cout << f->entrar(d);

    Data *d2 = new Data(5, 10, 10, 10, 10, 2010);

    cout << f->sair(d2);

    cout << f->sair(d2);

    // cout << d2->diferenca(d);
}

void testeCatraca(){

    Funcionario * f = new Funcionario(1, "Joao");
    Data* d = new Data(10, 10, 10, 10, 10, 2010);
    GerenciadorDeUsuario *g = new GerenciadorDeUsuario();
    Catraca* c = new Catraca (g);
    g->adicionar(f);
    cout << c->entrar(f->getId(), d);

    d = new Data(12, 10, 10, 10, 10, 2010);

    cout << c->sair(f->getId(), d);
}


void testePersistencia(){

    PersistenciaDeUsuario *p = new PersistenciaDeUsuario();

    p->carregar("usuarios");

}

void seiLa(){
        PersistenciaDeUsuario *p = new PersistenciaDeUsuario();
        GerenciadorDeUsuario *g = new GerenciadorDeUsuario();

        vector<Usuario*> *usuarios = p->carregar("usuarios.txt");

        for(int i = 0; i < usuarios->size(); i++){
            g->adicionar((*usuarios)[i]);
        }

        for(int i = 0 ; i < g->getUsuarios()->size(); i++){
            Funcionario *f = dynamic_cast<Funcionario*>(usuarios->at(i));
            if(f != nullptr){
                cout << f->getHorasTrabalhadas(9, 2024);
            }
        }


}

void testeRepetido(){

    GerenciadorDeUsuario *g = new GerenciadorDeUsuario();
    try{
    g->adicionar(new Aluno(1, "Joao"));
    g->adicionar(new Funcionario(1, "Joao"));

    }catch(invalid_argument *e){
        cout << e->what();
    }





}


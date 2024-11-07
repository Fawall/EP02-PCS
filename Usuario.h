#ifndef USUARIO_H
#define USUARIO_H

#include "Data.h"
#include <string>


using namespace std;

class Usuario {

    private:
        int id;
        string nome;

    public:
        Usuario(int id, string nome);
        virtual ~Usuario();

        string getNome();
        int getId();

        bool entrar(Data *d);
        bool sair(Data *d);
        virtual bool registrarEntradaManual(Data *d);
        virtual bool registrarSaidaManual(Data *d);


};

#endif
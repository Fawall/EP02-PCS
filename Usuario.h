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

        virtual string getNome();
        virtual int getId();

        virtual bool entrar(Data *d);
        virtual bool sair(Data *d);
        virtual bool registrarEntradaManual(Data *d);
        virtual bool registrarSaidaManual(Data *d);


};

#endif
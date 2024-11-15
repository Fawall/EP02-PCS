#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <vector>
#include "Usuario.h"
#include "Registro.h"
#include <string>


class Funcionario : Usuario {

    private:
        int id;
        string nome;
        vector<Registro* > *registros;

    public:
        Funcionario(int id, string nome);
        Funcionario(int id, string nome, vector<Registro* >* registros);

        virtual ~Funcionario();

        int getHorasTrabalhadas(int mes, int ano);
        vector<Registro* >* getRegistros();

        bool entrar(Data *d);
        bool sair(Data *d);
        bool registrarEntradaManual(Data *d);
        bool registrarSaidaManual(Data *d);
        string getNome();
        int getId();
        
};

#endif
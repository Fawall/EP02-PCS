#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <vector>
#include "Usuario.h"
#include "Registro.h"
#include <string>


class Funcionario {

    private:
        int id;
        string nome;
        vector<Registro* >* registros;

    public:
        Funcionario(int id, string nome);
        Funcionario(int id, string nome, vector<Registro* >* registros);

        virtual ~Funcionario();

        int getHorasTrabalhadas(int mes, int ano);
        vector<Registro* >* getRegistros();


};

#endif
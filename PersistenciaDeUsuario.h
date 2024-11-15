#ifndef PERSISTENCIADEUSUARIO_H
#define PERSISTENCIADEUSUARIO_H

#include <vector>
#include <iostream>
#include <string>

#include "Usuario.h"

class PersistenciaDeUsuario {

private:
    string arquivo;

public:
    PersistenciaDeUsuario();
    virtual ~PersistenciaDeUsuario();
    vector<Usuario*>* carregar(string arquivo);
    void salvar(string arquivo, vector<Usuario*>* v);

};

#endif
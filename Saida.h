#ifndef SAIDA_H
#define SAIDA_H
#include "Registro.h"

class Saida: public Registro {

private: 
    Data *d;
    bool manual;
public:

Saida(Data* d);
Saida(Data* d, bool manual);
virtual ~Saida();

};

#endif
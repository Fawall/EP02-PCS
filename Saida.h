#ifndef SAIDA_H
#include "Registro.h"

class Saida: public Registro {

private: 
    Data *d;

public:

Saida(Data* d);
Saida(Data* d, bool manual);
virtual ~Saida();

};

#endif;
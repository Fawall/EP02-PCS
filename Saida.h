#ifndef SAIDA_H
#include "Registro.h"

class Saida: public Registro {

public:

Saida(Data* d);
Saida(Data* d, bool manual);
virtual ~Saida();

};

#endif;
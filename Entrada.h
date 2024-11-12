#ifndef ENTRADA_H
#define ENTRADA_H

#include "Registro.h"
#include "Data.h"

class Entrada: public Registro {

private:
    Data *d;
    bool manual;
public:

    Entrada(Data* d);
    Entrada(Data* d, bool manual);
    virtual ~Entrada();

};

#endif
#ifndef ENTRADA_H
#include "Registro.h"
//#include "Data.h"

class Entrada: public Registro {

public:

    Entrada(Data* d);
    Entrada(Data* d, bool manual);
    virtual ~Entrada();

};

#endif;
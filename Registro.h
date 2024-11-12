#ifndef REGISTRO_H
#define REGISTRO_H

#include "Data.h"

class Registro {

private:
    Data* d;
    bool manual;

public:

    Registro(Data* d);               //posso escolher qual instancia criar
    Registro(Data* d, bool manual);

    virtual ~Registro();
    Data* getData();
    bool isManual();

};

#endif
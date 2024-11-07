#ifndef REGISTRO_H
#include "Data.h"

class Registro {

protected:

Data* d;
bool manual;

public:

Registro(Data* d);               //posso escolher qual instancia criar
Registro(Data* d, bool manual);

virtual ~Registro() = 0;
Data* getData();
bool isManual();

};

#endif;
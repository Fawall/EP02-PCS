#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>

class Aluno : Usuario
{


public:
    static const int HORARIO_INICIO = 6;
    Aluno(int id, string nome);
    virtual ~Aluno();

    static void setHorarioFim(int hora, int minuto);
    static int getHoraFim();
    static int getMinutoFim();

};


#endif
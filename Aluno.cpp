#include "Aluno.h"
#include <stdexcept>

using namespace std;

Aluno::Aluno(int id, string nome) : Usuario(id, nome) {
    this->id = id;
    this->nome = nome;
    
}

Aluno::~Aluno() {}

int Aluno::horaFim = 23;
int Aluno::minutoFim = 0;

void Aluno::setHorarioFim(int hora, int minuto) {

    if(hora < HORARIO_INICIO  || hora > 23)
        throw new logic_error("Hora invalida");
    if(minuto < 0 || minuto > 59)
        throw new logic_error("Minuto invalido");

    Aluno::horaFim = hora;    
    Aluno::minutoFim = minuto;
}

bool Aluno::entrar(Data *d) {
    if ((d->getHora() > HORARIO_INICIO || (d->getHora() == HORARIO_INICIO && d->getMinuto() >= 0)) &&
        (d->getHora() < getHoraFim() || (d->getHora() == getHoraFim() && d->getMinuto() <= getMinutoFim() ))) {
        return true;
    }
    return false;
}

bool Aluno::sair(Data *d) {
    return true;
}

int Aluno::getHoraFim() {
    return horaFim;
}

int Aluno::getMinutoFim() {
    return minutoFim;
}

bool Aluno::registrarEntradaManual(Data *d){
    return false;
}
bool Aluno::registrarSaidaManual(Data *d){
    return true;
}
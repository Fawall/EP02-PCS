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
}

bool Aluno::entrar(Data *d) {
    if(d->getHora() < 6 || d->getHora() > 22 && d->getMinuto() > 59 )
        return false;
    return true;
}

bool Aluno::sair() {
    return true;
}

bool Aluno::registrarEntradaManual(){
    return false;
}
bool Aluno::registrarSaidaManual(){
    return true;
}
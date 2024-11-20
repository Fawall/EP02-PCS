#include "PersistenciaDeUsuario.h"
#include "Usuario.h"
#include <stdexcept>
#include <fstream>
#include <istream>
#include "Aluno.h"
#include <sstream>
#include "Visitante.h"
#include "Registro.h"
#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"
#include "Data.h"

using namespace std;

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {}

vector<Usuario *> *PersistenciaDeUsuario::carregar(string arquivo)
{
    vector<Usuario *> *usuarios = new vector<Usuario *>();

    ifstream entrada;
    string linha, nome;
    int id;
    char tipo;

    entrada.open(arquivo);

    // Verificar existência de um Arquivo
    if (entrada.fail())
    {
        throw new logic_error("Arquivo nao encontrado ou formato incorreto");
    }

    while (getline(entrada, linha))
    {
        istringstream ss(linha);
        ss >> tipo;

        if (tipo == 'A')
        {
            ss >> id;
            ss >> nome;
            usuarios->push_back(new Aluno(id, nome));
        }
        else if (tipo == 'V')
        {
            int hora, minuto, segundo, dia, mes, ano;

            ss >> id;
            ss >> nome;
            ss >> hora;
            ss >> minuto;
            ss >> segundo;
            ss >> dia;
            ss >> mes;
            ss >> ano;

            Data *inicio = new Data(hora, minuto, segundo, dia, mes, ano);

            ss >> hora;
            ss >> minuto;
            ss >> segundo;
            ss >> dia;
            ss >> mes;
            ss >> ano;
            Data *fim = new Data(hora, minuto, segundo, dia, mes, ano);

            usuarios->push_back(new Visitante(id, nome, inicio, fim));
        }
        else if (tipo == 'F')
        {
            vector<Registro *> *registros = new vector<Registro *>();
            ss >> id;
            ss >> nome;

            if (getline(entrada, linha))
            {
                int quantidade_eventos = std::stoi(linha);

                if (quantidade_eventos == 0)
                {
                    Funcionario *f = new Funcionario(id, nome);
                    usuarios->push_back(f);
                }

                if (quantidade_eventos > 0)
                {
                    for (int i = 0; i < quantidade_eventos; ++i)
                    {
                        if (getline(entrada, linha))
                        {
                            std::istringstream eventoStream(linha);
                            char tipoEvento;
                            eventoStream >> tipoEvento;

                            if (tipoEvento == 'E')
                            {
                                int hora, minuto, segundo, dia, mes, ano, flag;

                                eventoStream >> hora;
                                eventoStream >> minuto;
                                eventoStream >> segundo;
                                eventoStream >> dia;
                                eventoStream >> mes;
                                eventoStream >> ano;
                                eventoStream >> flag;

                                Data *d = new Data(hora, minuto, segundo, dia, mes, ano);

                                if (flag != 0)
                                {
                                    Entrada *e = new Entrada(d, true);
                                    registros->push_back(e);
                                }
                                else
                                {
                                    Entrada *e = new Entrada(d);
                                    registros->push_back(e);
                                }
                            }
                            if(tipoEvento == 'S'){
                                int hora, minuto, segundo, dia, mes, ano, flag;

                                eventoStream >> hora;
                                eventoStream >> minuto;
                                eventoStream >> segundo;
                                eventoStream >> dia;
                                eventoStream >> mes;
                                eventoStream >> ano;
                                eventoStream >> flag;
                                
                                Data *d = new Data(hora, minuto, segundo, dia, mes, ano);

                                if (flag != 0)
                                {
                                    Saida *e = new Saida(d, true);
                                    registros->push_back(e);
                                }
                                else
                                {
                                    Saida *e = new Saida(d);
                                    registros->push_back(e);
                                }
                            }
                        }
                    }
                    Funcionario *f = new Funcionario(id, nome, registros);
                    usuarios->push_back(f);
                }
            }
        }

        // cout << (*usuarios)[0]->getNome() << endl;
    }
    entrada.close();
    return usuarios;

}

void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario *> *v)
{
    ofstream entrada;

    entrada.open(arquivo, ios_base::app);

    if(entrada.fail()){
        throw new logic_error("Arquivo nao encontrado ou formato incorreto");
    }

    for(unsigned int i = 0; i < v->size(); i++){
        Aluno* a = dynamic_cast<Aluno* >(v->at(i));
        if(a != nullptr){
            entrada << "A " << a->getId() << " " << a->getNome() << endl;
        }
        Funcionario* f = dynamic_cast<Funcionario* >(v->at(i));
        if(f != nullptr){
            entrada << "F " << f->getId() << " " << f->getNome() << endl;
            cout << f->getRegistros()->size() << endl;
            for(unsigned int i =0; i < f->getRegistros()->size(); i++){
                if(dynamic_cast<Entrada* >(f->getRegistros()->at(i)) != nullptr){
                    entrada << "E " << f->getRegistros()->at(i)->getData()->getHora() << " " << f->getRegistros()->at(i)->getData()->getMinuto() << " " << f->getRegistros()->at(i)->getData()->getSegundo() << " " << f->getRegistros()->at(i)->getData()->getDia() << " " << f->getRegistros()->at(i)->getData()->getMes() << " " << f->getRegistros()->at(i)->getData()->getAno() << " " << f->getRegistros()->at(i)->isManual()  << endl;
                }
                if(dynamic_cast<Saida* >(f->getRegistros()->at(i)) != nullptr){
                    entrada << "S " << f->getRegistros()->at(i)->getData()->getHora() << " " << f->getRegistros()->at(i)->getData()->getMinuto() << " " << f->getRegistros()->at(i)->getData()->getSegundo() << " " << f->getRegistros()->at(i)->getData()->getDia() << " " << f->getRegistros()->at(i)->getData()->getMes() << " " << f->getRegistros()->at(i)->getData()->getAno() << " " << f->getRegistros()->at(i)->isManual() << endl;
                }
            }
        }
        Visitante* vi = dynamic_cast<Visitante* >(v->at(i));
        if(vi != nullptr){
            entrada << "V " << vi->getId() << " " << vi->getNome() << " " << vi->getDataInicio()->getHora() << " " << vi->getDataInicio()->getMinuto() << " " << vi->getDataInicio()->getSegundo() << " " << vi->getDataInicio()->getDia() << " " << vi->getDataInicio()->getMes() << " " << vi->getDataInicio()->getAno() << " " << vi->getDataFim()->getHora() << " " << vi->getDataFim()->getMinuto() << " " << vi->getDataFim()->getSegundo() << " " << vi->getDataFim()->getDia() << " " << vi->getDataFim()->getMes() << " " << vi->getDataFim()->getAno() << endl;
        }

    }

    entrada.close();
}
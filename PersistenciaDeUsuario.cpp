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

    entrada.open(arquivo + ".txt");

    // Verificar existência de um Arquivo
    if (entrada.fail())
    {
        throw new logic_error("Arquivo não encontrado ou formato incorreto");
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
    for (int i = 0; i < usuarios->size(); i++)
    {
        if (dynamic_cast<Funcionario *>(usuarios->at(i)) != nullptr)
        {
            cout << dynamic_cast<Funcionario *>(usuarios->at(i))->getNome() << endl;
            cout << dynamic_cast<Funcionario *>(usuarios->at(i))->getRegistros()->size() << endl;
            cout << dynamic_cast<Funcionario *>(usuarios->at(i))->getHorasTrabalhadas(9, 2024);
        }
    }
}

void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario *> *v)
{

    ofstream entrada;

    entrada.open(this->arquivo, ios_base::app);

    // entrada << v->get << endl;

    entrada.close();

    //    if (!arquivoSaida.is_open()) {
    //         // Lança uma exceção logic_error se o arquivo não puder ser aberto
    //         throw new logic_error("Erro ao abrir o arquivo para salvar");
    //     }
}
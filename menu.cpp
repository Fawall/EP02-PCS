#include "Usuario.h"
#include "GerenciadorDeUsuario.h"
#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "Aluno.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Visitante.h"
#include "Funcionario.h"
#include "PersistenciaDeUsuario.h"

using namespace std;

void menu()
{

    Usuario *usuario;
    Funcionario *funcionario;
    Visitante *visitante;
    Aluno *aluno;

    Data *d;

    int escolha, id, mes, ano, hora, minuto, segundo, dia, catraca;
    char resposta, tipo, opcao;
    bool verifica;
    string nome, arquivo;

    GerenciadorDeUsuario *g = new GerenciadorDeUsuario();

    Catraca *c0 = new Catraca(g);
    Catraca *c1 = new Catraca(g);

    cout << "Deseja carregar usuarios (s/n): ";
    cin >> resposta;

    if (resposta == 's')
    {

        cout << "Arquivo: ";
        cin >> arquivo;
        PersistenciaDeUsuario *p = new PersistenciaDeUsuario();
        try
        {
            vector<Usuario *> *usuarios = p->carregar(arquivo);

            for (int i = 0; i < usuarios->size(); i++)
            {
                g->adicionar((*usuarios)[i]);
            }
        }
        catch (logic_error *e)
        {
            cout << e->what() << endl
                 << endl;
        }
    }

    do
    {

        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl;
        cout << "2) Saida" << endl;
        cout << "3) Registro manual" << endl;
        cout << "4) Cadastro de usuario" << endl;
        cout << "5) Relatorio" << endl;
        cout << "6) Configuracao" << endl;
        cout << "0) Sair" << endl;

        cout << "Escolha uma opcao: ";
        cin >> escolha;

        cout << endl;

        switch (escolha)
        {

        case 1:
        {
            try
            {
                cout << "Catraca: ";
                cin >> catraca;
                cout << "Id: ";
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
                cin >> minuto;
                cout << "Segundo: ";
                cin >> segundo;
                cout << "dia: ";
                cin >> dia;
                cout << "mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                d = new Data(hora, minuto, segundo, dia, mes, ano);

                if (c0->entrar(id, d) != true)
                {
                    cout << "[Entrada] Catraca " << catraca << " travada" << endl
                         << endl;
                }
                else
                {
                    cout << "[Entrada] Catraca " << catraca << " abriu: id " << id << endl
                         << endl;
                }
            }
            catch (invalid_argument *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }

            break;
        }

        case 2:
        {
            try
            {
                cout << "Catraca: ";
                cin >> catraca;
                cout << "Id: ";
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
                cin >> minuto;
                cout << "Segundo: ";
                cin >> segundo;
                cout << "dia: ";
                cin >> dia;
                cout << "mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                d = new Data(hora, minuto, segundo, dia, mes, ano);

                if (c1->sair(id, d) != true)
                {
                    cout << "[Saida] Catraca " << catraca << " travada" << endl
                         << endl;
                }
                else
                {
                    cout << "[Saida] Catraca " << catraca << " abriu: id " << id << endl
                         << endl;
                }
            }
            catch (invalid_argument *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }

            break;
        }

        case 3:
        {
            try
            {
                cout << "Entrada (e) ou Saida (s)? ";
                cin >> opcao;

                cout << "Id: ";
                cin >> id;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
                cin >> minuto;
                cout << "Segundo: ";
                cin >> segundo;
                cout << "dia: ";
                cin >> dia;
                cout << "mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                d = new Data(hora, minuto, segundo, dia, mes, ano);

                // condicao
                cout << "Entrada manual registrada: id " << id << endl;
            }
            catch (invalid_argument *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }

            break;
        }

        case 4:
        {
            try
            {
                cout << "Tipo (v, a ou f): ";
                cin >> tipo;

                if (tipo == 'v')
                {
                    Data *dataInicio;
                    Data *dataFim;

                    cout << "Id: ";
                    cin >> id;
                    cout << "Nome: ";
                    cin >> nome;
                    cout << "Data de inicio" << endl;
                    cout << "Hora: ";
                    cin >> hora;
                    cout << "Minuto: ";
                    cin >> minuto;
                    cout << "Segundo: ";
                    cin >> segundo;
                    cout << "dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Ano: ";
                    cin >> ano;

                    dataInicio = new Data(hora, minuto, segundo, dia, mes, ano);

                    cout << "Data de fim" << endl;
                    cout << "Hora: ";
                    cin >> hora;
                    cout << "Minuto: ";
                    cin >> minuto;
                    cout << "Segundo: ";
                    cin >> segundo;
                    cout << "dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Ano: ";
                    cin >> ano;

                    dataFim = new Data(hora, minuto, segundo, dia, mes, ano);

                    Visitante *v = new Visitante(id, nome, dataInicio, dataFim);
                    g->adicionar(v);
                    cout << "Visitante cadastrado com sucesso" << endl
                         << endl;
                }
                if (tipo == 'a')
                {
                    cout << "Id: ";
                    cin >> id;
                    cout << "Nome: ";
                    cin >> nome;

                    aluno = new Aluno(id, nome);
                    g->adicionar(aluno);
                    cout << "Aluno cadastrado com sucesso" << endl
                         << endl;
                }

                if (tipo == 'f')
                {
                    cout << "Id: ";
                    cin >> id;
                    cout << "Nome: ";
                    cin >> nome;

                    funcionario = new Funcionario(id, nome);
                    g->adicionar(funcionario);
                    cout << "Funcionario cadastrado com sucesso" << endl
                         << endl;
                }
            }
            catch (invalid_argument *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            break;
        }

        case 5:
        {
            try
            {
                cout << "Mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                cout << endl
                     << "Relatorio de horas trabalhadas" << endl;

                for (int i = 0; i < g->getUsuarios()->size(); i++)
                {
                    Funcionario *func = dynamic_cast<Funcionario *>(g->getUsuarios()->at(i));
                    if (func != nullptr)
                    {
                        cout << func->getNome() << ": " << func->getHorasTrabalhadas(mes, ano) << endl;
                    }
                }
                cout << endl;
            }
            catch (invalid_argument *e)
            {
                cout << e->what() << endl
                     << endl;
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }

            break;
        }

        case 6:
        {
            try
            {
                cout << "Horario de fim da janela dos Alunos" << endl;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minuto: ";
                cin >> minuto;

                aluno->setHorarioFim(hora, minuto);
            }
            catch (logic_error *e)
            {
                cout << e->what() << endl
                     << endl;
            }

            break;
        }

        case 0:
        {
            cout << "Deseja salvar usuarios (s/n)";
            cin >> resposta;

            if (resposta == 's')
            {
                cout << "Arquivo: ";
                cin >> arquivo;
                PersistenciaDeUsuario *p = new PersistenciaDeUsuario();
                try
                {
                    p->salvar(arquivo, g->getUsuarios());
                }
                catch (logic_error *e)
                {
                    cout << e->what() << endl
                         << endl;
                }
            }

            break;
        }
<<<<<<< HEAD
    }
    5
} while (escolha != 0);
=======
        }
>>>>>>> main

    } while (escolha != 0);
}
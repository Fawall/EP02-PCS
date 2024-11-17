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
    string nome;

    GerenciadorDeUsuario *g = new GerenciadorDeUsuario();

    Catraca *c0 = new Catraca(g);
    Catraca *c1 = new Catraca(g);

    cout << "Deseja carregar usuarios (s/n)" << endl;
    cin >> resposta;

    cout << "Arquivo: ";
    // cin >> txt;

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
            // condicao
            cout << "Catraca " << catraca << "abriu: id " << id << endl
                 << endl;
        }

        case 2:
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
            cout << "Saida " << catraca << "abriu: id " << id << endl
                 << endl;

            break;
        }

        case 3:
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

            break;
        }

        case 4:
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
                cout << "mes: ";
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
                cout << "mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                dataFim = new Data(hora, minuto, segundo, dia, mes, ano);

                Visitante *v = new Visitante(id, nome, dataInicio, dataFim);
                g->adicionar(v);
                cout << "Visitante cadastrado com sucesso";
            }
            if (tipo == 'a')
            {
                cout << "Id: ";
                cin >> id;
                cout << "Nome: ";
                cin >> nome;

                aluno = new Aluno(id, nome);
                g->adicionar(aluno);
                cout << "Aluno cadastrado com sucesso";
            }

            if (tipo == 'f')
            {
                cout << "Id: ";
                cin >> id;
                cout << "Nome: ";
                cin >> nome;

                funcionario = new Funcionario(id, nome);
                g->adicionar(funcionario);
                cout << "Funcionario cadastrado com sucesso";
            }

            break;
        }

        case 5:
        {
            cout << "mes: ";
            cin >> mes;
            cout << "ano";
            cin >> ano;

            cout << "Relatorio de horas trabalhadas" << endl;

            for (int i = 0; i < g->getUsuarios()->size(); i++)
            {
                Funcionario *func = dynamic_cast<Funcionario *>(g->getUsuarios()->at(i));
                if (funcionario != nullptr)
                {
                    cout << funcionario->getNome() << " Horas trabalhadas: " << funcionario->getHorasTrabalhadas(mes, ano) << endl;
                }
            }
            break;
        }

        case 6:
        {
            cout << "Horario de fim da janela dos Alunos" << endl;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
            cin >> minuto;

            break;
        }

        case 0:
        {
            cout << "Deseja salvar usuarios (s/n)";
            cin >> resposta;

            // codigo salvando usuarios

            break;
        }
        }

    } while (escolha != 0);
}
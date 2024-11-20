#include "Usuario.h"
#include "GerenciadorDeUsuario.h"
#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"

using namespace std;

void menu() {

    Usuario* usuario;
    Data *d;

    int escolha,id,mes,ano,hora,minuto,segundo,dia,catraca;
    char resposta,tipo,opcao;
    bool verifica;
    string nome;

    GerenciadorDeUsuario *g = new GerenciadorDeUsuario();
    
    Catraca *c0 = new Catraca(g);
    Catraca *c1 = new Catraca(g);

    cout << "Deseja carregar usuarios (s/n)" << endl;
    cin >> resposta;

    cout << "Arquivo: ";
    //cin >> txt;

do {

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

    switch (escolha) {

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

        //condicao
        cout << "Catraca " << catraca << " travada" << endl;

        //else condicao
        cout << "Catraca " << catraca << "abriu: id " << id << endl;


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

            //condicao
            cout << "Catraca " << catraca << "abriu: id " << id << endl;

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

            //condicao
            cout << "Entrada manual registrada: id " << id << endl;
            
            break;
        }

        case 4:
        {
            cout << "Tipo (v, a ou f): ";
            cin >> tipo;
            cout << "Id: ";
            cin >> id;
            cout << "Nome: ";
            cin >> nome;

            usuario = new Usuario(id,nome);

            //condicao
            cout << "Usuario cadastrado com sucesso";
            

            break;
        }

        case 5:
        {
            cout << "mes: ";
            cin >> mes;
            cout << "ano";
            cin >> ano;
            
            cout << "Relatorio de horas trabalhadas" << endl;
            cout << nome << ": ";
            //cout << getHorasTrabalhadas() << endl;

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
            
            //codigo salvando usuarios

            break;
        }
    }
    5
} while (escolha != 0);

}
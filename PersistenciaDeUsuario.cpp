#include "PersistenciaDeUsuario.h"
#include "Usuario.h"
#include <stdexcept>
#include <fstream>
#include "Aluno.h"

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {}

vector<Usuario*>* PersistenciaDeUsuario::carregar(string arquivo) {
    vector<Usuario*> *usuarios = new vector<Usuario*>();

    ifstream entrada;
    string linha, nome;
    int id;
    char tipo;

    entrada.open(arquivo+".txt");

    //Verificar existência de um Arquivo
    if (entrada.fail() ) {
        throw new logic_error("Arquivo não encontrado ou formato incorreto");
    }

    while(entrada >> tipo >> id >> nome){
        if(tipo == 'A'){
            Aluno *a = new Aluno(id, nome);
            usuarios->push_back(a);
        }
    }

    cout << (*usuarios)[1]->getNome() << endl;

    entrada.close();
    //return usuarios;

}

void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario*>* v) {

    ofstream entrada;

    entrada.open(this->arquivo, ios_base::app);

    //entrada << v->get << endl;

    entrada.close();


//    if (!arquivoSaida.is_open()) {
//         // Lança uma exceção logic_error se o arquivo não puder ser aberto
//         throw new logic_error("Erro ao abrir o arquivo para salvar");
//     }
    
}
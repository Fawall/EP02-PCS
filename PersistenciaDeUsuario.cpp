#include "PersistenciaDeUsuario.h"
#include "Usuario.h"
#include <stdexcept>
#include <fstream>

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {}

vector<Usuario*>* PersistenciaDeUsuario::carregar(string arquivo) {

    //vector<Usuario*>* usuarios = new vector<Usuario>;
    ofstream entrada;

    //Verificar existência de um Arquivo
    if (!std::ifstream(arquivo)) {
        throw new logic_error("Arquivo não encontrado ou formato incorreto");
    }

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
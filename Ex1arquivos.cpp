#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string nomeArquivo = "registros_pessoas.txt";
    string nome, cpf, dataNascimento, endereco;
    string resposta;

    while (true) {
        cout << "Digite os dados da pessoa:" << endl;
        cout << "nome: ";
        getline(cin, nome);
        cout << "cpf: ";
        getline(cin, cpf);
        cout << "data de nascimento (dd/mm/aaaa): ";
        getline(cin, dataNascimento);
        cout << "endereco: ";
        getline(cin, endereco);
        ofstream arquivo(nomeArquivo, ios::app);

        if (!arquivo) {
            cout << "erro ao abrir o arquivo!" << endl;
            return 1;
        }
        arquivo << "nome: " << nome << endl;
        arquivo << "cpf: " << cpf << endl;
        arquivo << "data de nascimento: " << dataNascimento << endl;
        arquivo << "endereco: " << endereco << endl;
        arquivo << endl;
        cout << "Deseja registrar outro cadastro para gravar no arquivo? (s/n): ";
        getline(cin, resposta);

        if (resposta == "n" || resposta == "N") {
            break;
        }
    }
    cout << "Arquivo gravado!" << endl;

    return 0;
}

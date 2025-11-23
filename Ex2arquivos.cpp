#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    FILE *arquivo;
    char ident[20], nome[100];
    int idade, numEstudantes = 0;
    int idadeMaisVelho = -1;
    char nomeMaisVelho[100];
    // Identidade, nome e idade devem ser colocados individualmente em cada linha
    arquivo = fopen("estudantes.txt", "r");

    if (arquivo == NULL) {
        perror("erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(ident, sizeof(ident), arquivo)) {
        fgets(nome, sizeof(nome), arquivo);
        fscanf(arquivo, "%d", &idade);
        fgetc(arquivo);
        numEstudantes++;

        if (idade > idadeMaisVelho) {
            idadeMaisVelho = idade;
            strcpy(nomeMaisVelho, nome);
        }
    }
    cout << "numero de estudantes lidos: " << numEstudantes << endl;
    cout << "estudante mais velho: " << nomeMaisVelho << idadeMaisVelho << " anos" << endl;
    fclose(arquivo);

    return 0;
}

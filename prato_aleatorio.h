#ifndef PRATO_ALEATORIO_H
#define PRATO_ALEATORIO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#define MAX_PRATOS 300000


struct Prato {
    int prioridade;
    int tempo;
    std::string nome;
};


std::string gerar_nome_aleatorio() {
    int tamanho = rand() % 10 + 1;  
    std::string nome = "";
    
    for (int i = 0; i < tamanho; i++) {
        char letra = 'a' + rand() % 26;  
        nome += letra;
    }
    
    return nome;
}


Prato gerar_prato_aleatorio() {
    Prato prato;
    
    prato.prioridade = rand() % 300001; 
    
    prato.tempo = rand() % 1001;  
    
    prato.nome = gerar_nome_aleatorio();
    
    return prato;
}

void gerar_pratos_aleatorios(Prato pratos[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        pratos[i] = gerar_prato_aleatorio();
    }
}

#endif
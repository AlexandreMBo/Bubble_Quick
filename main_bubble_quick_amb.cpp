#include <iostream>
#include "prato_aleatorio.h"
#include <ctime>

using namespace std;

bool comparar(const Prato& p1, const Prato& p2) {
    if (p1.prioridade != p2.prioridade) {
        return p1.prioridade > p2.prioridade;
    }
    return p1.tempo < p2.tempo;
}
// Bubble Sort
void bubble_sort(Prato pratos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!comparar(pratos[j], pratos[j + 1])) {
                Prato temp = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = temp;
            }
        }
    }
}

int partition(Prato pratos[], int low, int high) {
    Prato pivot = pratos[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (comparar(pratos[j], pivot)) {
            i++;
            Prato temp = pratos[i];
            pratos[i] = pratos[j];
            pratos[j] = temp;
        }
    }
    
    Prato temp = pratos[i + 1];
    pratos[i + 1] = pratos[high];
    pratos[high] = temp;
    return i + 1;
}
// Quick Sort
void quicksort(Prato pratos[], int low, int high) {
    if (low < high) {
        int pi = partition(pratos, low, high);
        quicksort(pratos, low, pi - 1);
        quicksort(pratos, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Digite o número de pratos: ";
    cin >> n;

    Prato pratos[MAX_PRATOS];
    
    gerar_pratos_aleatorios(pratos, n);

    clock_t inicio_bubble = clock();
    bubble_sort(pratos, n);
    clock_t fim_bubble = clock();
    double duracao_bubble = double(fim_bubble - inicio_bubble) / CLOCKS_PER_SEC;

    cout << "\nPratos ordenados com Bubble Sort (Top 10):" << endl;
    for (int i = 0; i < 10 && i < n; i++) {
        cout << "Prato " << i + 1 << ": " 
             << "Nome: " << pratos[i].nome 
             << ", Prioridade: " << pratos[i].prioridade 
             << ", Tempo: " << pratos[i].tempo << " minutos" << endl;
    }

    gerar_pratos_aleatorios(pratos, n);

    clock_t inicio_quick = clock();
    quicksort(pratos, 0, n - 1);
    clock_t fim_quick = clock();
    double duracao_quick = double(fim_quick - inicio_quick) / CLOCKS_PER_SEC;

    cout << "\nPratos ordenados com Quicksort (Top 10):" << endl;
    for (int i = 0; i < 10 && i < n; i++) {
        cout << "Prato " << i + 1 << ": " 
             << "Nome: " << pratos[i].nome 
             << ", Prioridade: " << pratos[i].prioridade 
             << ", Tempo: " << pratos[i].tempo << " minutos" << endl;
    }

    cout << "\nTempo Bubble Sort: " << duracao_bubble << " segundos." << endl;
    cout << "Tempo Quicksort: " << duracao_quick << " segundos." << endl;

    return 0;
}
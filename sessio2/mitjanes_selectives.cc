#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

void selecciona(vector<bool>& assig, int S) {
    int aux;
    for (int i = 0; i < S; ++i) {
        cin >> aux;
        assig[aux-1] = true;
    }
}

void calcula(vector<Estudiant>& vest, const vector<bool>& assig, int S, int N) {
    int dni;
    for (int i = 0; i < vest.size(); ++i) {
        cin >> dni;
        Estudiant est(dni);
        vest[i] = est;
        double total = 0;
        double nota;
        for (int j = 0; j < N; ++ j) {
            cin >> nota;
            if (assig[j]) {
                total += nota;
            }
        }
        total = total/S;
        vest[i].afegir_nota(total);
    }
}

void escriu(const vector<Estudiant>& v) {
    for (int i = 0; i < v.size(); ++i) v[i].escriure();
}

int main() {
    int M, N, S; //estudiants, assignatures, nº seleccionades
    cin >> M >> N >> S;
    vector<bool> assig(N,false); 
    selecciona(assig,S); //seleccionades per la mitjana
    vector<Estudiant> vest(M);
    calcula(vest,assig,S,N);
    escriu(vest);
}

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

void llegir(vector<Estudiant>& vest) {
    int DNI;
    double nota;
    for (int i = 0; i < vest.size(); ++i) {
     vest.llegir();
  }
}

int n_est_diferents(const vector<Estudiant>& vest) {
    int count;
    int dni_actual = 0;
    for (int i = 0; i < vest.size(); ++i) {
            if (vest[i].consultar_DNI() != dni_actual) {
             ++count;
             dni_actual = vest[i].consultar_DNI();
            }
    }
    return count;
}

void simplifica(const vector<Estudiant>& vest, vector<Estudiant>& result) {
  int j = -1;
  int dni = -1;
  //int tam = v.size();
  for (int i = 0; i < vest.size(); ++i) {
    int DNI = vest[i].consultar_DNI();
    if(DNI != dni) {
      dni = DNI;
      ++j;
      Estudiant e(DNI);
      result[j] = e;
      if (vest[i].te_nota()) result[j].afegir_nota(vest[i].consultar_nota());
    }
    else {
      if (vest[i].te_nota()) {
        if (result[j].te_nota()) {
          double nota = vest[i].consultar_nota();
          if (result[j].consultar_nota() < nota) result[j].modificar_nota(nota);
        }
        else result[j].afegir_nota(vest[i].consultar_nota());
      }
    }
  }
}

void escriure(const vector<Estudiant>& vest) {
        for(int i = 0; i < vest.size(); ++i) {
                vest[i].escriure();
        }
}

int main() {
 int n;
 cin >> n;
 vector<Estudiant> vest(n);
 llegir(vest);
 vector<Estudiant> result(n_est_diferents(vest));
 simplifica(vest,result);
 escriure(result);
}

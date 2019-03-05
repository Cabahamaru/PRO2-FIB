#include "Dades.hh"

Dades::Dades() {}

Dades::~Dades() {}

int Dades::consultar_n() const {
  return n;
}

int Dades::consultar_l0() const {
  return l0;
}

int Dades::consultar_lx() const {
  return lx;
}

int Dades::consultar_ly() const {
  return ly;
}

int Dades::consultar_li(int i) const {
  return l[i];
}

void Dades::llegir_dades() {
  cin >> n >> l0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    l.push_back(x);
  }
  cin >> lx >> ly;
}
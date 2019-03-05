#include "Parell_cromosoma.hh"

Parell_cromosoma::Parell_cromosoma() {}

Parell_cromosoma::~Parell_cromosoma() {}

vector<bool> Parell_cromosoma::consultar_c1() const {
  return c1;
}

vector<bool> Parell_cromosoma::consultar_c2() const {
  return c2;
}

void Parell_cromosoma::encreuament_normals(const Dades& d, const Parell_cromosoma& a, const Parell_cromosoma& b, int i)  {
  bool m, p;
  cin >> m >> p;
  int k;
  cin >> k;
  if (m) c1 = a.consultar_c2();
  else c1 = a.consultar_c1();
  if (p) c2 = b.consultar_c2();
  else c2 = b.consultar_c1();
  for (int j = k; j < d.consultar_li(i-1); ++j) {
    swap(c1[j],c2[j]);
  }
}

void Parell_cromosoma::encreuament_sexuals(const Dades& d, const Parell_cromosoma& a, const Parell_cromosoma& b, string& genere) {
  bool m, p;
  cin >> m >> p;
  int k;
  cin >> k;
  if (m) c1 = a.consultar_c2();
  else c1 = a.consultar_c1();
  if (p) {
    genere = "Y";
    c2 = b.consultar_c2();
  }
  else {
    genere = "X";
    c2 = b.consultar_c1();
  }
  for (int i = k; i < d.consultar_l0(); ++i) {
    swap(c1[i],c2[i]);
  }
}

void Parell_cromosoma::llegir_cromosomes_sexuals(const Dades& d, string sexe) {
  for (int i = 0; i < d.consultar_lx(); ++i) {
    string x;
    cin >> x;
    if (x == "1") c1.push_back(true);
    else c1.push_back(false);
  }
  if (sexe == "X") {
    for (int j = 0; j < d.consultar_lx(); ++j) {
      string x;
      cin >> x;
      if (x == "1") c2.push_back(true);
      else c2.push_back(false);
    }
  }
  else {
    for (int z = 0; z < d.consultar_ly(); ++z) {
      string x;
      cin >> x;
      if (x == "1") c2.push_back(true);
      else c2.push_back(false);
    }
  }
}

void Parell_cromosoma::llegir_cromosomes_normals(const Dades& d, int i) {
  for (int j = 0; j < d.consultar_li(i); ++j) {
    string x;
    cin >> x;
    if (x == "1") c1.push_back(true);
    else c1.push_back(false);
  }
  for (int z = 0; z < d.consultar_li(i); ++z) {
    string x;
    cin >> x;
    if (x == "1") c2.push_back(true);
    else c2.push_back(false);
  }
}

void Parell_cromosoma::escriure_cromosoma_c1() const {
  for (int i = 0; i < c1.size(); ++i) {
    cout << ' ' << c1[i];
  }
}

void Parell_cromosoma::escriure_cromosoma_c2() const {
  for (int j = 0; j < c2.size(); ++j) {
    cout << ' ' << c2[j];
  }
}

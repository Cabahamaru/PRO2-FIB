#include "Individu.hh"

Individu::Individu() {}

Individu::~Individu() {}


string Individu::consultar_genere() const {
  return sexe;
}

string Individu::consultar_nom() const {
  return nom;
}

bool Individu::te_pares() const {
  if (pare == "$") return false;
  else return true;
}

string Individu::consultar_pare() const {
  return pare;
}

string Individu::consultar_mare() const {
  return mare;
}

Parell_cromosoma Individu::consultar_parell_c(int i) const {
  return genotip[i];
}

void Individu::fer_fill(const Dades& d, const Individu& m, const Individu& p, const string nom) {
  this->nom = nom;
  Parell_cromosoma s;
  string g;
  s.encreuament_sexuals(d,m.consultar_parell_c(0),p.consultar_parell_c(0),g);
  genotip.push_back(s);
  sexe = g;
  for (int i = 1; i <= d.consultar_n(); ++i) {
    Parell_cromosoma n;
    n.encreuament_normals(d,m.consultar_parell_c(i),p.consultar_parell_c(i),i);
    genotip.push_back(n);
  }
  pare = p.consultar_nom();
  mare = m.consultar_nom();
}

void Individu::llegir_individu(const Dades& d) {
  cin >> nom;
  cin >> sexe;
  Parell_cromosoma s; 
  s.llegir_cromosomes_sexuals(d,sexe); //lectura dels sexuals
  genotip.push_back(s); //emmagatzematge dels sexuals
  for (int i = 0; i < d.consultar_n(); ++i) {
    Parell_cromosoma norm; 
    norm.llegir_cromosomes_normals(d,i); //lectura dels normals
    genotip.push_back(norm); //emmagatzematge dels normals
  }
  pare = "$";
  mare = "$";
}

void Individu::escriure_genotip() const {
  cout << "escribir_genotipo " << nom << endl;
  cout << "  X:";
  genotip[0].escriure_cromosoma_c1();
  cout << endl;
  if (sexe == "X") cout << "  X:";
  else cout << "  Y:";
  genotip[0].escriure_cromosoma_c2();
  cout << endl;
  for (int i = 1; i < genotip.size(); ++i) {
    cout << "  " << i << ".1:";
    genotip[i].escriure_cromosoma_c1();
    cout << endl;
    cout << "  " << i << ".2:";
    genotip[i].escriure_cromosoma_c2();
    cout << endl;
  }
}

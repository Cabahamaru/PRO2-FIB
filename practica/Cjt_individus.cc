#include "Cjt_individus.hh"

Cjt_individus::Cjt_individus() {}

Cjt_individus::~Cjt_individus() {}

Individu Cjt_individus::consultar_individu(string nom) const {
  map<string, Individu>::const_iterator it = poblacio.find(nom);
  return (*it).second;
}

bool Cjt_individus::existeix_individu(string nom) const {
  map<string, Individu>::const_iterator it = poblacio.find(nom);
  if (it == poblacio.end()) return false;
  else return true;
}

void Cjt_individus::afegir_individu(const Individu &x) {
  cout << "anadir_individuo " << x.consultar_nom() << endl;
  if (existeix_individu(x.consultar_nom())) cout << "  error" << endl;
  else poblacio[x.consultar_nom()] = x;
}

 bool Cjt_individus::son_germans(string a, string b) const {
   string pare1, pare2, mare1, mare2;
   if (not consultar_individu(a).te_pares() and not consultar_individu(b).te_pares()) return false; //cap dels dos te pares
   else if (consultar_individu(a).te_pares() and not consultar_individu(b).te_pares()) return false; //a te pares, b no en te
   else if (not consultar_individu(a).te_pares() and consultar_individu(b).te_pares()) return false; //a no te pares, b en te
   else { //ambdos tenen pares
     pare1 = consultar_individu(a).consultar_pare();
     mare1 = consultar_individu(a).consultar_mare();
     pare2 = consultar_individu(b).consultar_pare();
     mare2 = consultar_individu(b).consultar_mare();
     if (pare1 == pare2 or mare1 == mare2) return true;
     else return false;
   }
 }

bool Cjt_individus::son_antecessors(string a, string b) const {
  if (a == b) return true;
  else if (not consultar_individu(a).te_pares()) return false;
  else {
    string pareaux, mareaux;
    pareaux = consultar_individu(a).consultar_pare();
    mareaux = consultar_individu(a).consultar_mare();
    bool aux1 = son_antecessors(pareaux,b);
    bool aux2 = son_antecessors(mareaux,b);
    return (aux1 or aux2);
  }
}

void Cjt_individus::reproduccio(const Dades& d, const string m, const string p, string fill) {
  cout << "reproduccion_sexual " << m << ' ' << p << ' ' << fill << endl;
  if (not existeix_individu(m)) cout << "  error" << endl;
  else if (not existeix_individu(p)) cout << "  error" << endl;
  else if (existeix_individu(fill)) cout << "  error" << endl;
  else if (consultar_individu(m).consultar_genere() != "X") cout << "  no es posible reproduccion" << endl;
  else if (consultar_individu(p).consultar_genere() != "Y") cout << "  no es posible reproduccion" << endl;
  else if (son_germans(m,p)) cout << "  no es posible reproduccion" << endl;
  else if (son_antecessors(m,p)) cout << "  no es posible reproduccion" << endl;
  else if (son_antecessors(p,m)) cout << "  no es posible reproduccion" << endl;
  else {
    Individu x, y;
    x = consultar_individu(m);
    y = consultar_individu(p);
    Individu f;
    f.fer_fill(d,x,y,fill);
    poblacio[fill] = f;
  }
}

void Cjt_individus::llegir_arbre(Arbre<string>& a, string marca) {
  Arbre<string> a1;
  Arbre<string> a2;
  string x;
  cin >> x;
  if (x!= marca) {
    llegir_arbre(a1,marca);
    llegir_arbre(a2,marca);
    a.plantar(x,a1,a2);
  }
}
  
void Cjt_individus::escriure_complet() {
  Arbre<string> a;
  llegir_arbre(a,"$");
  queue<string> q;
  string nom = a.arrel();
  cout << "completar_arbol_genealogico " << nom << endl;
  if (existeix_individu(nom) and completar(a,q,nom)) {
    cout << ' ';
    while (not q.empty()) {
      cout << ' ' << q.front();
      q.pop();
    }
    cout << endl;
  }
  else cout << "  no es arbol parcial" << endl;  
}

void Cjt_individus::preordre(string nom, queue<string>& q) const {
  string aux = "*"+nom+"*";
  q.push(aux);
  if (consultar_individu(nom).te_pares()) {
    string pare = consultar_individu(nom).consultar_pare();
    string mare = consultar_individu(nom).consultar_mare();
    preordre(pare,q);
    preordre(mare,q);
  }
  else {
    q.push("$");
    q.push("$");
  }
}

bool Cjt_individus::completar(Arbre<string>& a, queue<string>& q, const string nom) {
  bool b = true;
  if (a.es_buit() and nom != "$") {
     preordre(nom,q);
  }
  else if (not a.es_buit() and nom != "$") {
      if (a.arrel() == nom) {
        q.push(nom);
        Arbre<string> a1, a2;
        a.fills(a1,a2);
        string nom1, nom2;
        nom1 = consultar_individu(nom).consultar_pare();
        nom2 = consultar_individu(nom).consultar_mare();
        //cout << nom1 << " " << nom2 << endl;
        bool b1 = completar(a1,q,nom1);
        bool b2;
        if (b1) b2 = completar(a2,q,nom2);
        b = b1 and b2;
      }
      else return false;
    }
  else if (not a.es_buit() and nom == "$") return false;
  else q.push("$");
  return b;
}
  
void Cjt_individus::llegir_cjt_individus(const Dades& d) {
  cin >> m;
  for (int i = 0; i < m; ++i) {
    Individu a;
    a.llegir_individu(d);
    poblacio[a.consultar_nom()] = a;
  }
}

void Cjt_individus::escriure_cjt_individus() const {
  cout << "escribir_poblacion" << endl;
  map<string, Individu>::const_iterator it = poblacio.begin();
  while (it != poblacio.end()) {
    cout << "  ";
    Individu a;
    a = (*it).second;
    cout << a.consultar_nom() << ' ';
    cout << 'X' << a.consultar_genere() << ' ';
    string b, c;
    b = a.consultar_pare();
    c = a.consultar_mare();
    cout << '(' << b << ',' << c << ')' << endl;
    ++it;
  } 
}

void Cjt_individus::escriure_nivells(string nom) const {
  cout << "escribir_arbol_genealogico " << nom << endl;
  queue<string> q;
  int k = 0;
  q.push(nom);
  while (!q.empty()) {
    int count = q.size();
    cout << "  Nivel " << k << ":";
    while (count > 0) {
      string s = q.front();
      cout << " " << s;
      q.pop();
      if (consultar_individu(s).te_pares()) {
        q.push(consultar_individu(s).consultar_pare());
        q.push(consultar_individu(s).consultar_mare());
      }
      --count;
    }
    ++k;
    cout << endl;
  }
}






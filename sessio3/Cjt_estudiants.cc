#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
    nest = 0;
    vest = vector<Estudiant> (MAX_NEST);
    imax = -1; //cjt_estudiants buit, no hi ha estudiant amb nota maxima
}

Cjt_estudiants::~Cjt_estudiants() {}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
    if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
    int i = nest - 1;
    bool trobat = false;
    int dni = est.consultar_DNI();
    while (i >= 0 and not trobat) {
        if (dni > vest[i].consultar_DNI()) trobat = true;
        else {
            vest[i+1] = vest[i];
            --i;
        }
    }
    vest[i+1] = est;
    ++nest;
    recalcular_posicio_imax();
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x) {
  int i;
  bool found = false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}

void Cjt_estudiants::recalcular_posicio_imax() {
    double nota_max = -1;
    int imax_aux = -1;
    for (int i = 0; i < nest; ++i) {
        if (vest[i].te_nota()) {
            if (vest[i].consultar_nota() > nota_max) {
                imax_aux = i;
                nota_max = vest[i].consultar_nota();
            }
            else if (vest[i].consultar_nota() == nota_max) {
                if (vest[i].consultar_DNI() < vest[imax_aux].consultar_DNI()) {
                    imax_aux = i;
                    nota_max = vest[i].consultar_nota();
                }
            }
        }
    }
    imax = imax_aux;
}

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
    int x = est.consultar_DNI();
    int i = cerca_dicot(vest,0,nest-1,x);
    vest[i] = est;
    recalcular_posicio_imax();
}

void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i-1] = est;
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}

void Cjt_estudiants::esborrar_estudiant(int dni) {
/* Pre: existeix un estudiant al parametre implıcit amb DNI = dni */
/* Post: el parametre implıcit conte els mateixos estudiants que 
l’original menys l’estudiant amb DNI = dni */
    int i = 0;
    bool trobat = false;
    while (not trobat and i < nest) {
        if (vest[i].consultar_DNI() == dni) trobat = true;
        ++i;
    }
    if (not trobat) throw PRO2Excepcio("L'estudiant no està en el conjunt");
    for (int j = i ; j < nest; ++j) {
        vest[j-1] = vest[j];
    }
    --nest;
    if (i-1 == imax) recalcular_posicio_imax();
}

int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,comp);
}

Estudiant Cjt_estudiants::estudiant_nota_max( ) const {
/* Pre: el parametre implıcit conte almenys un estudiant amb nota */
/* Post: el resultat es l’estudiant del parametre implıcit amb 
nota maxima; si en te mes d’un,es el de DNI mes petit */
    if (imax == -1) throw PRO2Excepcio("No hi ha cap estudiant amb nota");
    else return vest[imax];
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i) vest[i].llegir();
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}









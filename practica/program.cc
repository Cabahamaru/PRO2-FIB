/**
 * @mainpage Experiments genètics en el laboratori.
    
Es tracta de simular experiments genètics de laboratori partint d'una població d'indivus
d'una espècie determinada i provar diferents accions sobre aquests, ja sigui reproduint-los, afegint nous individus
al conjunt, descriure el seu genotip, arbre genealògic, entre d'altres.
S'introdueixen les classes <em>Cromosoma</em>, <em>Individu</em> i <em>Cjt_individus</em>.
*/
   
/** @file program.cc
    @brief Programa principal <em>Simulació genètica</em>.
*/

#include "Dades.hh"
#include "Cjt_individus.hh"
#include "Individu.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <queue>
#endif

using namespace std;

/** @brief Programa principal <em>Simulació d'experiments genètics</em>. */
int main() {
  Dades d;
  d.llegir_dades();
  Cjt_individus conjunt;
  conjunt.llegir_cjt_individus(d);
  string s;
  cin >> s;
  while (s != "acabar") {
    if (s == "anadir_individuo") {
      Individu a;
      a.llegir_individu(d);
      conjunt.afegir_individu(a);
    }
    else if (s == "reproduccion_sexual") {
      string a, b, c;
      cin >> a >> b >> c;
      conjunt.reproduccio(d,a,b,c);
    }
    else if (s == "escribir_arbol_genealogico") {
      string nom;
      cin >> nom;
      if (conjunt.existeix_individu(nom)) {
        conjunt.escriure_nivells(nom);
      }
      else cout << "escribir_arbol_genealogico " << nom << endl << "  error" << endl;
    }
    else if (s == "completar_arbol_genealogico") {
      conjunt.escriure_complet();
    }
    else if (s == "escribir_poblacion") {
      conjunt.escriure_cjt_individus();
    }
    else if (s == "escribir_genotipo") {
      string nom;
      cin >> nom;
      if (conjunt.existeix_individu(nom)) {
        conjunt.consultar_individu(nom).escriure_genotip();
      }
      else cout << "escribir_genotipo " << nom << endl << "  error" << endl;
    }
    cin >> s;
  }
  cout << "acabar" << endl;
}
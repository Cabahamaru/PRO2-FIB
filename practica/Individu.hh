/** @file Individu.hh
    @brief Especificació de la classe Individu
 */
#ifndef _INDIVIDU_HH_
#define _INDIVIDU_HH_

#include "Dades.hh"
#include "Parell_cromosoma.hh"
 
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;
 
/** @class Individu
    @brief Representa un individu d'una espècie determinada
 */
class Individu {
   
  private:
  string nom;
  string sexe;
  string pare;
  string mare;
  vector<Parell_cromosoma> genotip;
  
  public:
  
  //Constructores
  
/** @brief Creadora per defecte
      S'executa automàticament al crear un Individu
   *  \pre Cert.
   *  \post El resultat és un objecte Individu
   */
  Individu();
   
  //Destructores
   
/** @brief Destructora per defecte
      S'executa automàticament al destruir un Individu
   *  \pre Cert.
   *  \post El resultat esborra un Individu
   */
  ~Individu();
  
  //Consultores
  
/** @brief Consulta el genere de l'Individu.
   *  \pre Cert.
   *  \post El resultat és Y si els cromosomes sexuals del p.i. són XY, y X si son XX
   */
  string consultar_genere() const;
  
/** @brief Consulta el nom de l'Individu.
   *  \pre Cert.
   *  \post El resultat és el nom del p.i.
   */
  string consultar_nom() const;
  
/** @brief Consulta si el p.i. té pares
   *  \pre Cert.
   *  \post El resultat és true si cap dels punters pare i mare del p.i. apunten a NULL, false altrament
   */
  bool te_pares() const;
  
/** @brief Consulta el pare del p.i.
   *  \pre Cert.
   *  \post El resultat és l'objecte individu apuntat per l'apuntador pare del p.i.
   */
  string consultar_pare() const;
  
/** @brief Consulta la mare del p.i.
   *  \pre Cert.
   *  \post El resultat és l'objecte individu apuntat per l'apuntador mare del p.i.
   */
  string consultar_mare() const;
  
/** @brief Consulta el parell ièssim de cromosomes de l'Individu.
   *  \pre 0 <= i <= n.
   *  \post El resultat és un objecte Parell_cromosoma de la posició i del vector genotip del p.i..
   */
  Parell_cromosoma consultar_parell_c(int i) const;
  
  //Modificadores
  
/** @brief Consulta la mare del p.i.
   *  \pre Cert.
   *  \post Guarda en el p.i. un nou individu resultat de la reproduccio entre mare i pare, amb NOM=nom,
            MARE=mare, PARE=pare, i el vector genotip resultant de l'encreuament dels cromosomes dels pares.
   */
  void fer_fill(const Dades& d, const Individu& mare, const Individu& pare, const string nom);

  /* Entrada / Sortida */
  
/** @brief Llegeix un Individu.
   *  \pre Cert.
   *  \post Guarda l'Individu que es llegeix en el paràmetre implícit.
   */
  void llegir_individu(const Dades& d);
  
/** @brief Escriu el genotip de l'individu
   *  \pre Cert.
   *  \post Escriu pel canal estàndar de sortida la cadena de gens emmagatzemada en el p.i..
   */
  void escriure_genotip() const;
};
  
#endif
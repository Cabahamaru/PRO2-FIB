/** @file Dades.hh
    @brief Especificació de la classe Dades
 */
#ifndef _DADES_HH_
#define _DADES_HH_
 
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;
 
/** @class Dades
    @brief Representa el conjunt de dades genètiques que comparteixen els individus d'una mateixa espècie
 */
class Dades {
   
  private:
  int n; //nombre de parells de cromosomes normals
  int l0; //part comú del creuament dels cromosomes sexuals
  int lx; //longitud del cromosoma sexual X
  int ly; //longitud del cromosoma sexual Y
  vector<int> l; //longituds dels n parells de cromosomes normals
  
  public:
  
  //Constructores

/** @brief Creadora per defecte
      S'executa automàticament al crear un objecte Dades
   *  \pre Cert.
   *  \post El resultat és un objecte Dades
   */
  Dades();
  
  //Destructores
   
/** @brief Destructora per defecte
      S'executa automàticament al destruir un objecte Dades
   *  \pre Cert.
   *  \post El resultat esborra un objecte Dades
   */
  ~Dades();
  
  //Consultores
  
/** @brief Consulta el nombre de parells de cromosomes normals.
   *  \pre Cert.
   *  \post El resultat és el camp n del p.i..
   */
  int consultar_n() const;
  
/** @brief Consulta la part comuna dels cromosomes sexuals.
   *  \pre Cert.
   *  \post El resultat és el camp l0 del p.i..
   */
  int consultar_l0() const;
  
/** @brief Consulta la longitud del cromosoma sexual X.
   *  \pre Cert.
   *  \post El resultat és el camp lx del p.i..
   */
  int consultar_lx() const;
  
/** @brief Consulta la longitud del cromosoma sexual Y.
   *  \pre Cert.
   *  \post El resultat és el camp ly del p.i..
   */
  int consultar_ly() const;
  
/** @brief Consulta la longitud del parell ièssim de cromosomes.
   *  \pre Cert.
   *  \post El resultat és el ièssim valor del vector l del p.i..
   */
  int consultar_li(int i) const;
  
    /* Entrada / Sortida */
  
/** @brief Llegeix les dades proporcionades.
   *  \pre El canal estàndard d'entrada conté les dades de l'espècie.
   *  \post Guarda el conjunt de dades a l'objecte Dades.
   */
  void llegir_dades();

};
#endif
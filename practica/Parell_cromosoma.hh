/** @file Parell_cromosoma.hh
    @brief Especificació de la classe Parell_cromosoma
 */
#ifndef _PARELL_CROMOSOMA_HH_
#define _PARELL_CROMOSOMA_HH_

#include "Dades.hh"
 
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;
 
/** @class Parell_cromosoma
    @brief Representa un parell de cromosomes d'un individu.
 */
class Parell_cromosoma {
   
  private:
  vector<bool> c1;
  vector<bool> c2;
  
/** @brief Consulta el primer cromosoma del parell.
   *  \pre Cert.
   *  \post Retorna el vector c1 del p.i..
   */
  vector<bool> consultar_c1() const;
  
/** @brief Consulta el segon cromosoma del parell.
   *  \pre Cert.
   *  \post Retorna el vector c2 del p.i..
   */
  vector<bool> consultar_c2() const;
  
  public:
  //Constructores
  
  
/** @brief Creadora per defecte
      S'executa automàticament al crear un Parell_cromosoma
   *  \pre Cert.
   *  \post El resultat és un Parell_cromosoma amb seq. de gens de longitud l.
   */
  Parell_cromosoma();
  
  //Destructores
   
/** @brief Destructora per defecte
      S'executa automàticament al destruir un Parell_cromosoma
   *  \pre Cert.
   *  \post El resultat esborra un Parell_cromosoma
   */
  ~Parell_cromosoma();
  
  //Consultores

  
  //Modificadores
  
/** @brief S'encarrega d'encreuar els gens per la reproducció sexual de cromosomes normals
   *  \pre Cert.
   *  \post El resultat és un cromosoma c1 que conté els gens de 0 a k del cromosoma indicat de a, i els gens de k+1 a li
            del cromosoma indicat de b, i un cromosoma c2 amb els gens de 0 a k del cromosoma indicat de b i els gens de k+1 a li
            del cromosoma indicat de a.
   */
  void encreuament_normals(const Dades& d, const Parell_cromosoma& a, const Parell_cromosoma& b, int i);
  
/** @brief S'encarrega d'encreuar els gens per la reproducció sexual de cromosomes sexuals
   *  \pre Cert.
   *  \post El resultat és un cromosoma c1 que conté els gens de 0 a k i de l0+1 a lx del cromosoma indicat de a, i de
            k+1 a l0 els gens del cromosoma indicat, i un cromosoma c2 que (X o Y depenent del cromosoma escollit del pare),
            amb els gens de 0 a k i de l0+1 a lx/y del cromosoma indicat de b, i els gens de k+1 a l0 del cromosoma indicat de a.
   */
  void encreuament_sexuals(const Dades& d, const Parell_cromosoma& a, const Parell_cromosoma& b, string& genere);
  
  
  /* Entrada / Sortida */
  
/** @brief Llegeix un cromosoma normal.
   *  \pre Cert.
   *  \post Guarda el cromosoma que es llegeix en el paràmetre implícit.
   */
  void llegir_cromosomes_normals(const Dades& d, int i);
  
/** @brief Llegeix un cromosoma sexual.
   *  \pre Cert.
   *  \post Guarda el cromosoma que es llegeix en el paràmetre implícit.
   */
  void llegir_cromosomes_sexuals(const Dades& d, string sexe);
  
/** @brief Escriu el primer cromosoma del parell.
   *  \pre Cert.
   *  \post Escriu el vector c1 del p.i..
   */
  void escriure_cromosoma_c1() const;
  
  /** @brief Escriu el segon cromosoma del parel.
   *  \pre Cert.
   *  \post Escriu el vector c2 del p.i..
   */
  void escriure_cromosoma_c2() const;
};
  
#endif
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
/** @file Cjt_individus.hh
    @brief Especificació de la classe Cjt_individus
 */
#ifndef _CJT_INDIVIDUS_HH_
#define _CJT_INDIVIDUS_HH_

#include "Dades.hh"
#include "Individu.hh"
#include "Arbre.hh"
 
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <queue>
#endif

using namespace std;
 
/** @class Cjt_individus
    @brief Representa una població d'organismes d'una espècie determinada
 */
class Cjt_individus {
   
  private:
  int m; //individus inicials sense ascendents
  map<string, Individu> poblacio;
  
  public:
  
/** @brief Creadora per defecte
      S'executa automàticament al crear un Cjt_individus
   *  \pre Cert.
   *  \post El resultat és un Cjt_individus no inicialitzat
   */
  Cjt_individus();
  
  //Destructores
   
/** @brief Destructora per defecte
      S'executa automàticament al destruir un Cjt_individus
   *  \pre Cert.
   *  \post El resultat esborra un Cjt_individus
   */
  ~Cjt_individus();
  
  //Consultores  
  
/** @brief Consulta un individu del p.i.
   *  \pre Existeix un Individu en el p.i. amb NOM=nom.
   *  \post El resultat és l'individu del p.i amb NOM=nom.
   */
  Individu consultar_individu(string nom) const;
  
/** @brief Consulta si l'individu es troba en el p.i.
   *  \pre Cert.
   *  \post El resultat és true si l'individu amb NOM=nom es troba en el p.i., false altrament.
   */
  bool existeix_individu(string nom) const;
  
/** @brief Consulta si els individus a i b son germans.
   *  \pre a i b existeixen en el conjunt.
   *  \post El resultat és true si l'individu a te el mateix pare o la mateixa mare que b, false altrament.
   */
  bool son_germans(string a, string b) const;
  
/** @brief Consulta si l'individu b és antecessor de a.
   *  \pre a i b existeixen en el conjunt.
   *  \post El resultat és true si b forma part de l'arbre genealogic de a, false altrament.
   */
  bool son_antecessors(string a, string b) const;
  
  //Modificadores
  
/** @brief Afegeix un nou individu al p.i..
   *  \pre Cert.
   *  \post S'ha afegit l'individu x al p.i, si x ja existia en la poblacio, escriu error.
   */
  void afegir_individu(const Individu& x);
  
/** @brief Comprova si es pot reproduir dos Individus.
   *  \pre Cert.
   *  \post es crearà un individu fill si, mare existeix i els seus cromosomes sexuals son XX, pare existeix
            i els seus cromosomes sexuals son XY, fill no existeix, i mare i pare no son germans ni antecessors un de l'altre,
            donat el cas comença el procés de reproducció.
   */
  void reproduccio(const Dades& d, const string mare, const string pare, const string fill);
  
/** @brief Guarda un arbre genealògic en preordre.
   *  \pre Cert.
   *  \post Guarda a q l'arbre genealògic de l'Individu amb NOM=nom en preordre.
   */
  void preordre(string nom, queue<string>& q) const;
  
/** @brief Completa un arbre genealogic i el guarda.
   *  \pre a no és buit, q és buida, nom és l'arrel de a.
   *  \post si l'arbre a és un arbre parcial de l'arbre genealogic de l'Individu amb NOM=nom, aleshores la funció
            retorna true i el completa guardant-lo a q marcant els nous nodes, si no ho és la funció retorna false.
   */
  bool completar(Arbre<string>& a, queue<string>& q, const string nom);
  
  /* Entrada / Sortida */
  
/** @brief Llegeix un Cjt_individus.
   *  \pre Estan preparats al canal estàndard d'entrada un enter positiu que representa el nombre d'elements
           que llegirem, i les dades de tals nombre d'individus diferents.
   *  \post El p.i. conté el conjunt d'individus llegits emmagatzemats per ordre alfabètic
   */
  void llegir_cjt_individus(const Dades& d);
  
/** @brief Llegeix un Arbre.
   *  \pre a és buit; el canal estàndar d'entrada conté el recorregut en preordre
           d'un arbre binari A d'enters marcat amb "marca"
   *  \post a=A
   */
  void llegir_arbre(Arbre<string>& a, string marca);
  
/** @brief Escriu el conjunt d'individus.
   *  \pre Cert.
   *  \post S'han escrit pel canal estàndard de sortida els Individus del p.i. en ordre alfabetic per nom,
            continuat pel seu sexe i els seu pare i mare de cada un
   */
  void escriure_cjt_individus() const;

/** @brief Escriu el conjunt d'individus.
   *  \pre Existeix un Individu amb NOM=nom en el conjunt.
   *  \post S'ha escrit pel canal estàndard de sortida l'arbre genealògic de l'Individu per nivells.
   */
  void escriure_nivells(string nom) const;
  
/** @brief Completa un arbre genealògic si és parcial i l'escriu.
   *  \pre Hi ha preparat al canal estàndard d'entrada un arbre genealògic escrit en preordre.
   *  \post Si l'abre llegit és parcial, es completa i s'escriu pel canal estàndard de sortida, altrament no fa indica que no és parcial.
   */
  void escriure_complet();
};

#endif
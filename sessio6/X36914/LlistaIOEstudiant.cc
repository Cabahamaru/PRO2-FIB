#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    Estudiant est;
    list<Estudiant>::iterator it = l.begin();
    est.llegir();
    while (est.consultar_DNI() != 0) {
        l.insert(it,est);
        est.llegir();
    }
}

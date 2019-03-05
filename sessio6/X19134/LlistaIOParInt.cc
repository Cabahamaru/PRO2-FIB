#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  ParInt x;
  list<ParInt>::iterator it = l.begin();
  while (x.llegir()) {
    l.insert(it,x);
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  ParInt x;
  list<ParInt>::const_iterator it = l.begin();
  while (it != l.end()) {
    x = *it;
    x.escriure();
    ++it;
  }
}

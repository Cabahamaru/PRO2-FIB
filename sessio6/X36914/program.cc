#include <iostream>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"
#include <list>

using namespace std;

int search(list<Estudiant>& l, int dni) {
    int count  = 0;
    list<Estudiant>::const_iterator it = l.begin();
    while (it != l.end()) {
        if ((*it).consultar_DNI() == dni) ++count;
        ++it;
    }
    return count;
}

int main() {
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);
    int dni;
    cin >> dni;
    cout << dni << ' ' << search(l,dni) << endl;
}

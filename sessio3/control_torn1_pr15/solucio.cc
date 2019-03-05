#include "Cjt_estudiants.hh"
 
 
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    b = false;
    int p = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
    if (vest[p].consultar_DNI() == est.consultar_DNI()) b = true;
    if (!b) {
        nest++;
        for (int i = nest - 1; i > p; i--) {
            vest[i] = vest[i-1];
        }
        vest[p] = est;
        if (vest[p].te_nota()){
            suma_notes += est.consultar_nota();
            nest_amb_nota++;
        }
    }
}
 
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    b = false;
    int i = 0;
    while (!b and i < nest) {
        if (vest[i].consultar_DNI() == dni) b = true;
        ++i;
    }
    if (b) {
        if (vest[i-1].te_nota()){
            suma_notes -= vest[i-1].consultar_nota();
            --nest_amb_nota;
        }
        for (int j = i; j < nest; ++j) {
            vest[j-1] = vest[j];
        }
        --nest;
    }
 
}

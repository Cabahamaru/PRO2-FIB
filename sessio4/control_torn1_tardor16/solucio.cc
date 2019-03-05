 #include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
  bool trobat = false;
  int i = primer_est_amb_nota;
  while (!trobat and i < nest) {
    if (vest[i].consultar_nota() >= nota_b) trobat = true;
    ++i;
  }
  if (trobat) return i;
  else return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
  trobat = false;
  int p = cerca_lineal_per_dni(vest,0,nest-1,est.consultar_DNI());
  if (p != nest) trobat = true;
  if (!trobat) {
    ++nest;
    if (est.te_nota()) {
        int i = cerca_dicot_per_nota_dni(vest,primer_est_amb_nota,nest-1,est);
        //mirem si el estudiant que estem afegint es el primer del vector amb nota
        if (!vest[primer_est_amb_nota].te_nota()) {
            primer_est_amb_nota = i; //si ho es, aquest esdeve el primer_est_amb_nota
        }
        for (int j = nest-1; j > i; --j) {
         vest[j] = vest[j-1];   
        }
        vest[i] = est;
    }
    else {
        int i = cerca_dicot_per_dni(vest,0,primer_est_amb_nota-1,est.consultar_DNI());
        for (int j = nest-1; j > i; --j) {
            vest[j] = vest[j-1];
        }
        vest[i] = est;
        ++primer_est_amb_nota;
    }
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const
{
    for (int i = posicio_nota(nota_i); i < nest; ++i) {
      if (vest[i].consultar_nota() <= nota_s) {
            vest[i].escriure();
      }
  }
}

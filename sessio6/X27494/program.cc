#include <iostream>
using namespace std;

struct Pair {
    int codi;
    int nombre;
};

void actualitza(const list<Pair> l, const int op, const int num, int& min, int& max, double& mitjana) {
    if (p.codi == -1) {
        ++count;
        sumatotal += p.nombre;
        if (min > p.nombre) min = p.nombre;
        if (max < p.nombre) max = p.nombre;
        mitjana = sumatotal/count;
    }
    else if (p.codi == -2) {
        --count;
        sumatotal -= p.nombre;
        
    }
}

int main() {
    list<Pair> l;
    int op, num;
    int min, max;
    int min = max = 0;
    double mitjana = 0;
    cin >> op >> num;
    while (op != 0 and num != 0) {
        actualitza(l,op,num,min,max,mitjana);
        if (max == -1 and min == -1) cout << '0' << endl;
        else cout << min << ' ' << max << ' ' << mitjana << endl;
        cin >> p.codi >> p.nombre;
    }
}

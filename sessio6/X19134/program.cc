#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
#include <list>

using namespace std;

void search(list<ParInt>& l, int n, int& count, int& suma) {
  list<ParInt>::iterator it = l.begin();
  while (it != l.end()) {
    if ((*it).primer() == n) {
      ++count;
      suma += (*it).segon();
    }
    ++it;
  }
}

int main() {
  list<ParInt> l;
  LlegirLlistaParInt(l);
  int n;
  cin >> n;
  int count = 0;
  int suma = 0;
  search(l,n,count,suma);
  cout << n << ' ' << count << ' ' << suma << endl;
}

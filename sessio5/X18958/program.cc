#include <iostream>
#include "ParInt.hh"
#include "PilaIOParInt.hh"
#include <stack>

using namespace std;

bool search(stack<ParInt> p, int x) {
    bool trobat = false;
    while (!trobat and !p.empty()) {
        if (p.top().primer() == x) trobat = true;
        p.pop();
    }
    return trobat;
}


int main() {
    stack<ParInt> p;
    llegirPilaParInt(p);
    int x;
    cin >> x;
    escriurePilaParInt(p);
    if (search(p,x)) {
        cout << p.top().segon() << endl;
    }
    else cout << "No trobat" << endl;
    
}

#include "PilaIOParInt.hh"

void llegirPilaParInt(stack<ParInt>& p) {
    ParInt x;
    while (x.llegir()) {
        p.push(x);
    }
}

void escriurePilaParInt(stack<ParInt> p) {
    ParInt x;
    while (!p.empty()) {
        x = p.top();
        x.escriure();
        p.pop();
    }
}

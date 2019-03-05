#include <iostream>
#include <stack>
using namespace std;

bool calcul_exp() {
	stack<char> s;
	char p;
	while (cin >> p and p != '.') {
		s.push(p);
	}
	int par_o_c = 0, cla_o_c = 0, aux;
	bool cla_o = false, par_o = false;
	while (!s.empty()) {
		aux = s.top();
		if (aux == '(') {
			par_o_c--;
			if (cla_o) return false;
			par_o = false;
		}
		else if (aux == ')') {
			par_o_c++;
			par_o = true;
			cla_o = false;

			
		}
		else if (aux == '[') {
			cla_o_c--;
			if (par_o) return false;
			cla_o = false;

		}
		else if (aux == ']') {
			par_o = false;
			cla_o = true;
			cla_o_c++;

		}
		s.pop();
		if (par_o_c < 0 or cla_o_c < 0) return false;
	}
	if (par_o_c != 0 or cla_o_c != 0) return false;
	return true;
}



int main() {
	if (calcul_exp()) cout << "Correcte" << endl;
	else cout << "Incorrecte" << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Partit {
        int x, y;
};

//Matriu dels resultats dels partits
typedef vector<Partit> Row;
typedef vector<Row> Matrix;

//Matriu de la classificacio de la lliga
typedef vector<int> Fila;
typedef vector<Fila> Matriu;
 
void llegir_matriu(Matrix& M) {
        int tam = M.size();
        for (int i = 0; i < tam; ++i) {
                for (int j = 0; j < tam; ++j) {
                        cin >> M[i][j].x >> M[i][j].y;
                }
        }
}
 
void classificacio(Matriu& R, const Matrix& M) {
        int tam = R.size();
        //Número equip
        for (int i = 0; i < tam; ++i) R[i][0] = i+1;
        //Puntuacio
        for (int i = 0; i < tam; ++i) {
                for (int j = 0; j < tam; ++j) {
                        if (i != j) {
                                //Punts
                                if (M[i][j].x == M[i][j].y) {
                                        ++R[i][1];
                                        ++R[j][1];
                                }
                                else if (M[i][j].x > M[i][j].y) R[i][1] += 3;
                                else R[j][1] += 3;
                                //Gols a favor
                                R[i][2] += M[i][j].x;
                                R[j][2] += M[i][j].y;
                                //Gols en contra
                                R[i][3] += M[i][j].y;
                                [j][3] += M[i][j].x;
                        }
                }
        }
}
 
 
void escriure_matriu(const Matriu& R) {
        int tam = R.size();
        for (int i = 0; i < tam; ++i) {
                for (int j = 0; j < 4; ++j) {
                        if (j != 0) cout << " ";
                        cout << R[i][j];
                } cout << endl;
        }
}
 
 
int main() {
        int n;
        cin >> n;
        Matrix M(n, Row(n));
        llegir_matriu(M);
        Matriu R(n, Fila(4,0));
        classificacio(R,M);
        //sort???
        escriure_matriu(R);
}

#include <iostream>
#include <vector>
using namespace std;

void max_min_v(const vector<int>& v) {
    int max = v[0];
    int min = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (max < v[i]) max = v[i];
        if (min > v[i]) min = v[i];
    }
    cout << max << ' ' << min << endl;
}

int main() {
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; ++i) cin >> v[i];
 max_min_v(v);
}

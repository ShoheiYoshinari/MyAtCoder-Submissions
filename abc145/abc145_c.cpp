#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int N, X[8], Y[8];
int main() {
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];

    vector<int> ord;
    rep(i, N) ord.push_back(i);

    long double sm = 0;
    do {
        rep(i, N - 1) {
            int a = ord[i];
            int b = ord[i + 1];

            long double dx = X[a] - X[b];
            long double dy = Y[a] - Y[b];

            sm += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(ord.begin(), ord.end()));

    rep(i, N) sm /= (i + 1);
    cout << fixed << setprecision(15) << sm << endl;
    
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> S;
    rep(i, k) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    sort(S.begin(), S.end());

    rep(i, k) cout << S[i] << endl;
}

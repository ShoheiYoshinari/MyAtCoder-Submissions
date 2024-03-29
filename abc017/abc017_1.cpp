#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int s[3], e[3];
    rep(i, 3){
        cin >> s[i] >> e[i];
    }
    int sum = 0;
    rep(i, 3){
        sum += s[i]*e[i]/10;
    }
    cout << sum << endl;
}
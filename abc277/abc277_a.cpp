#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,x;
    cin >> n >> x;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = -1;
    rep(i, n){
        if(p[i] == x){
            ans = i;
            break;
        }
    }
    cout << ans + 1 << endl;
}
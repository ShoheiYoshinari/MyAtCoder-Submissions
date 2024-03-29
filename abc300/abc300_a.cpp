#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n ,a ,b;
    cin >> n >> a >> b;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    int ans = 0;
    rep(i, n){
        if(c[i] == a + b) {
            ans = i;
            break;
        }
    }
    cout << ans+1 << endl;
}
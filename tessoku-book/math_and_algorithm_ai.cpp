#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main(){
    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n+1), s(n+1);
    a[0] = 0;
    s[0] = 0;

    rep(i, n){
        cin >> a[i];
        s[i] += s[i-1] + a[i];
    }
    rep(i, q){
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }

}
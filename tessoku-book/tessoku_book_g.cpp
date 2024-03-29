#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main(){
    int d, n, l, r;
    cin >> d >> n;
    vector<int> a(d+2, 0), s(d+2, 0);

    rep(i, n){
        cin >> l >> r;
        a[l]++, a[r+1]--;
    }
    rep(i, d) s[i] += s[i-1] + a[i];
    rep(i, d) cout << s[i] << endl;
}

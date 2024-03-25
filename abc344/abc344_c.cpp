#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n, m, l, q;
int a[109], b[109], c[109], x[200009];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> m;
    rep(i, m) cin >> b[i];
    cin >> l;
    rep(i, l) cin >> c[i];
    cin >> q;
    rep(i, q) cin >> x[i];

    set<int> num;

    rep(i, n){
        rep(j, m){
            rep(k, l){
                num.insert(a[i] + b[j] + c[k]);
            }
        }
    }

    rep(i, q){
        if(num.count(x[i])){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
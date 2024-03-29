#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    vector<int> p(n), q(n), v(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    rep(i, n) v[i] = i + 1;

    int idx = 0, a = -1, b = -1;
    do{
        bool ok = true;
        rep(i, n){
            if(p[i] != v[i]) ok = false;
        }
        if(ok) a = idx;

        ok = true;
        rep(i, n){
            if(q[i] != v[i]) ok = false;
        }
        if(ok) b = idx;

        idx++;
    }while(next_permutation(v.begin(), v.end()));

    cout << abs(a - b) << endl;

}
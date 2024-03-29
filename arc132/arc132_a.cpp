#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int n, q;
    cin >> n;
    vector<int> r(n+1), c(n+1);
    rep(i, n) cin >> r[i];
    rep(i, n) cin >> c[i];
    cin >> q;

    rep(i, q){
        int a, b;
        cin >> a >> b;
        int rr = r[a], cc = c[b];
        if(rr + cc >= n + 1){
            cout << '#';
        }else{
            cout << '.';
        }
    }
    cout << endl;
 
}
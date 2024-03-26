#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n, a[109];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    rep(i, n-1){
        cout << a[i] * a[i+1] << endl;
    }
    return 0;
}
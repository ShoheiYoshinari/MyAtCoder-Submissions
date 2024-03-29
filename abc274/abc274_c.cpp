#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    map<int, int> a;

    a[1] = 0;

    rep(i, n){
        int t;
        cin >> t;
        a[2*i] = a[t] + 1;
        a[2*i + 1] = a[t] + 1;   
    }
    rep(i, 2*n+1){
        cout << a[i] << endl;
    }

}                               
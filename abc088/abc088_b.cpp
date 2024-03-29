#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    int alice = 0,bob = 0;
    rep(i, n){
        if(i%2 == 1){
            alice += a[i];
        }else{
            bob += a[i];
        }
    }
    cout << abs(alice - bob) << endl;
}
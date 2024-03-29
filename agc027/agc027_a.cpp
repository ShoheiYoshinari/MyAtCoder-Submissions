#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    rep(i, n){
        if(a[i] <= x){
            x -= a[i];
        }else{
            cout << i << endl;
            return 0;
        }
    }
    if(x > 0){
        cout << n - 1 << endl;
    }else{
        cout << n << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int n, k, q, aa;
    cin >> n >> k >> q;
    vector<int> a(n, 0);

    rep(i, q){
        cin >> aa;
        a[aa-1]++;
    }
    rep(i, n){
        if(k - q + a[i] > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
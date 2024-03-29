#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int n,q; 
    cin>>n>>q;
    vector<int> a(101, 0);

    rep(i, q){
        int l,r,t;
        cin>>l>>r>>t;
        for(int p = l; p <= r; p++){
            a[p] = t;
        }
    }

    rep(i, n) cout << a[i] << endl;
}

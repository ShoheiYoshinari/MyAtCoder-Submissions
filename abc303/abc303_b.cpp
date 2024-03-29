#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    int a[m][n];
    rep(i, m){
        rep(j, n) cin >> a[i][j];
    }

    set<pair<int,int>> p;
    long long ans = 0;
    rep(i, m){
        rep(j, n-1){
            p.insert(make_pair(a[i][j],a[i][j+1]));
        }
    }
    rep(i, m){
        for(int j = n-1; j > 0; j--){
            p.insert(make_pair(a[i][j],a[i][j-1]));
        }
    }
    ans = (n*(n-1)/2) - p.size()/2;
    cout << ans << endl;
    
    
}
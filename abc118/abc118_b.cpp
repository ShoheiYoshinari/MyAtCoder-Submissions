#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> like(m, 0);

    int k, a, cnt = 0;
    
    rep(i, n){
        cin >> k;
        rep(j, k){
            cin >> a;
            like[a-1]++;
        }
    }
    rep(i, m){
        if(like[i] == n) cnt++;
    }
    cout << cnt << endl;
}
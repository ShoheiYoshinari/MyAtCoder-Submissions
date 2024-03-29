#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ent(100009, 0);
    vector<int> s(100009, 0);

    int l, r, cnt = 0;
    rep(i, m-1){
        cin >> l >> r;
        ent[l]++;
        ent[r+1]--;
    }
    rep2(i, 1, n){
        s[i] = s[i-1] + ent[i];
    }
    rep(i, n){
        if(s[i] == m) cnt++;
    }
    cout << cnt << endl;
}
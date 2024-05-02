#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    int r, c;
    cin >> r >> c;
    vector s(r, vector(c, 0));
    rep(i, r) rep(j, c) cin >> s[i][j]; 

    int ans = 0;
    rep(i, 1<<r){
        auto ss = s;
        rep(j, r){
            if(!(i & (1<<j))) continue;
            rep(k, c) ss[j][k] = 1 - ss[j][k];
        }
    
        int cnt = 0;
        rep(k, c){
            int tate_cnt = 0;
            rep(j, r) if(ss[j][k] == 0) tate_cnt++;
            cnt += max(tate_cnt, r - tate_cnt);
        }
        ans = max(ans, cnt); 
    }
    cout << ans << endl;
    return 0;
}

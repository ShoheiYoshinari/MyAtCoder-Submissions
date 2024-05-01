#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m, k;

int main(){
    cin >> n >> m;
    vector<int> k(m), p(m);
    vector<vector<int> > s(m);
    rep(i, m){
        cin >> k[i];
        s[i].resize(k[i]);
        rep(j, k[i]) cin >> s[i][j];
    }
    rep(i, m) cin >> p[i];

    int ans = 0;

    rep(i, 1<<n){
        bool ok = true;
        string str = "";
        rep(j, n){
            int wari = 1 << j;
            if((i/wari)%2 == 1) str += '1';
            else str += '0';
        }
        rep(j, m){
            int cnt = 0;
            rep(t, k[j]){
                if(str[s[j][t]-1] == '1') cnt++;
            }
            if(cnt%2 != p[j]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;


}
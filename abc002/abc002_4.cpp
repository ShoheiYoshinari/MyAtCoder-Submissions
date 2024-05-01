#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, m;
int main(){
    cin >> n >> m;
    vector<int> x(m), y(m);
    rep(i, m) cin >> x[i] >> y[i];

    int relate[n+1][n+1];
    rep(i, n+1) rep(j, n+1) relate[i][j] = 0;
    rep(i, m){
        relate[x[i]][y[i]]++;
        relate[y[i]][x[i]]++;
    }

    int ans = 1;
    vector<int> candi;

    rep(i, 1<<n){
        int cnt = 0;
        rep(j, n){
            int wari = 1 << j;
            if((i/wari)%2 == 1){
                candi.push_back(j+1);
                cnt++;
            }
        }
        
        bool ok = true;
        rep(k, candi.size()){
            rep(l, candi.size()){
                if(k <= l) continue;
                if(relate[candi[k]][candi[l]] != true) ok = false;
            }
        }
        if(ok) ans = max(ans, cnt);
        candi.clear();
    }
    cout << ans << endl;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, m, k;
int a[109], b[109], c[109], d[109];

int main(){
    cin >> n >> m;
    rep(i, m) cin >> a[i] >> b[i];
    cin >> k;
    rep(i, k) cin >> c[i] >> d[i];

    int ans = -1;
    int cnt[109];
    rep(i, 1<<k){
        rep(j, n+1) cnt[j] = 0;
        rep(j, k){
            int wari = (1 << j);
            if((i/wari)%2 == 1) cnt[c[j]]++;
            else cnt[d[j]]++;
        }
        int tmp = 0;
        rep(j, m){
            if(cnt[a[j]] >= 1 && cnt[b[j]] >= 1) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;

}
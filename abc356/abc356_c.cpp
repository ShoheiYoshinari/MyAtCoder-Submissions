#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(m);
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<char> r(m);

    rep(i, m){
        cin >> c[i];
        rep(j, c[i]){
            int tmp;
            cin >> tmp;
            tmp--;
            a[i][tmp]++;
        }
        cin >> r[i];
    }

    ll ans = 0;
    rep(i, 1<<n){
        vector<int> sum(m, 0);

        rep2(j, 1, n){
            // 39~41行目は以下の処理で簡潔にコードできる
            if(i & (1 << (j-1))){ //：iのjbit目が１であれば処理
            //int wari = (1 << (j-1));
            //honnmono
            //if((i/wari)%2 == 1){
                rep(vi, m){
                    if(a[vi][j-1]) sum[vi]++;
                }
            }
        }
        bool ok = true;
        rep(j, m){
            if((r[j] == 'o' && sum[j] >= k)||(r[j] == 'x' && sum[j] < k)){
            }else{
                ok = false;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;

}

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const double pi = 3.141592653589793238;
const int INF = 2147483647;
const ll INFLL = 1LL << 62;
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define rep(i, r, n) for (int i = r; i < (int)n; i++)
#define pb push_back


void solve(){
    int n, q;
    cin >> n >> q;

    int ans = 0;
    vector<bool> s(q, false);
    rep(i, 0, q){
        int a;
        cin >> a;
        a--;


        if(s[a] == false){
            if(a == 0){
                if(s[1] == false) ans++;
            }else if(a == n-1){
                if(s[n-2] == false) ans++;
            }else{
                int cnt_w = 0, cnt_b = 0;
                if(s[a-1] == false) cnt_w++;
                else cnt_b++;
                if(s[a+1] == false) cnt_w++;
                else cnt_b++;

                if(cnt_w == 2) ans++;
                if(cnt_b == 2) ans--;
            }
        }else{
            if(a == 0){
                if(s[1] == false) ans--;
            }else if(a == n-1){
                if(s[n-2] == false) ans--;
            }else{
                int cnt_w = 0, cnt_b = 0;
                if(s[a-1] == false) cnt_w++;
                else cnt_b++;
                if(s[a+1] == false) cnt_w++;
                else cnt_b++;

                if(cnt_w == 2) ans--;
                if(cnt_b == 2) ans++;
            }
        }

        s[a] = !s[a];
        cout << ans << endl;
    }
    return;
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}
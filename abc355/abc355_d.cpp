#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    int max_r = 0;
    vector<pair<int, int>> p;
    rep(i, n){
        int l , r;
        cin >> l >> r;
        p.emplace_back(l, 0);
        p.emplace_back(r, 1);
    }
    sort(all(p));
    ll ans = 0;
    ll cur = 0;
    for(auto [x, t] : p){
        if(t == 0){
            ans += cur;
            cur++;
        }else{
            cur--;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

using ll = long long;

int main(){
    ll l, r;
    cin >> l >> r;
    vector<pair<ll ,ll>> ans;
    while(l < r){
        for(int i = 60; i >= 0; i--){
            ll w = 1ll << i;
            if(l%w) continue;
            if(l+w > r) continue;
            ans.emplace_back(l, l+w);
            l += w;
            break;
        }
    }

    cout << ans.size() << endl;
    for(auto [l, r] : ans) cout << l << ' ' << r << endl;
    return 0;
}
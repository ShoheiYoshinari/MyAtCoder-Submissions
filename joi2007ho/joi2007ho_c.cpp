#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

ll n, x, y;
vector<pair<ll, ll> > pos;
vector<vector<bool> > is_there(5001, vector<bool>(5001));

bool search(ll x, ll y){
    if(x < 0 || x > 5000 || y < 0 || y > 5000) return false;
    return is_there[x][y];
}

int main(){
    cin >> n;
    rep(i, n){
        cin >> x >> y;
        pos.emplace_back(x, y);
        is_there[x][y] = true;
    }

    ll ans = 0;
    rep(i, n){
        rep2(j, i+1, n){
            ll dist_x = pos[j].first - pos[i].first;
            ll dist_y = pos[j].second - pos[i].second;
            ll x1 = pos[j].first + dist_y;
            ll y1 = pos[j].second - dist_x;
            ll x2 = pos[i].first + dist_y;
            ll y2 = pos[i].second - dist_x;
            ll x3 = pos[j].first - dist_y;
            ll y3 = pos[j].second + dist_x;
            ll x4 = pos[i].first - dist_y;
            ll y4 = pos[i].second + dist_x;
            
            if((search(x1, y1) && search(x2, y2)) || (search(x3, y3) && search(x4, y4))){
                ans = max(ans, dist_x*dist_x + dist_y*dist_y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
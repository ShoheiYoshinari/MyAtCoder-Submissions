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

map<ll, ll> mp;

ll sreach(ll x){
    if(x <= 1) return 0;
    if(mp.count(x)) return mp[x];
    return mp[x] =  sreach(x/2) + sreach((x+1)/2) + x;
}

int main(){
    ll n;
    cin >> n;
    cout << sreach(n) << endl;

}
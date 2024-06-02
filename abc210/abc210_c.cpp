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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    map<int, int> mp;
    rep(i, k) mp[c[i]]++;

    int ans = mp.size();
    rep2(i, k, n){
        mp[c[i]]++;
        mp[c[i-k]]--;
        if(mp[c[i-k]] == 0) mp.erase(c[i-k]);
        int res = mp.size();
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
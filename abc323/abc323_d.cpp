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
    int n;
    cin >> n;
    vector<int> s(n), c(n);
    map<ll, ll> mp;
    int cnt = 0;
    rep(i, n){
        cin >> s[i] >> c[i];
        cnt += c[i];
        mp[s[i]] = c[i];
    }

    bool ok = true;
    while(ok){
        ok = false;
        for(auto p : mp){
            if(p.second >= 2){
                mp[p.first * 2] += p.second / 2;
                cnt -= p.second / 2;
                if(mp[p.first * 2] >= 2) ok = true;
                if(p.second%2 == 1) mp[p.first] = 1;
                else mp[p.first] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
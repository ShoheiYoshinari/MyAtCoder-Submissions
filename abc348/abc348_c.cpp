#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n;
map<int, int> mp;

int main(){
    cin >> n;
    int a, c;
    rep(i, n){
        cin >> a >> c;
        if(!mp.count(c)) mp[c] = a;
        else{
            if(mp[c] > a) mp[c] = a;
        }
    }

    int ans = -1;

    for(auto p : mp){
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}
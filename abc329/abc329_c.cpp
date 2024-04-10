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
string s;

int main(){
    cin >> n >> s;
    map<char, int> mp;

    char now = s[0];
    mp[s[0]]++;
    int cnt = 1;

    rep2(i, 1, n){
        if(s[i] == now){
            cnt++;
        }else{
            now = s[i];
            cnt = 1;
        }
        if(mp[s[i]] < cnt) mp[s[i]] = cnt;
    }

    int ans = 0;
    for(auto p : mp){
        ans += p.second;
    }
    cout << ans << endl;
    return 0;


}
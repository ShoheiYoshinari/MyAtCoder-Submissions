#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    rep(i, 1000){
        string key = to_string(i);
        if(key.size() == 1) key = "00" + key;
        if(key.size() == 2) key = '0' + key;

        int pos = 0;
        rep(i, n){
            if(s[i] == key[pos]) pos++;
            if(pos == 3){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
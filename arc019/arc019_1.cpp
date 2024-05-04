#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main(){
    string s;
    cin >> s;

    string ans = "";

    string ck = "ODIZSB";
    string repair = "001258";
    rep(i, s.size()){
        char tmp = s[i];
        rep(j, ck.size()){
            if(tmp == ck[j]) ans += repair[j];
        }
        if(ans.size() != i+1) ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
string s;
int main(){
    bool ck = true;
    cin >> s;
    rep(i, s.size()){
        if(s[i] == '|'){
            if(ck) ck = false;
            else ck = true;
            continue;
        }
        if(ck) cout << s[i];
    }
    cout << endl;
    return 0;
}
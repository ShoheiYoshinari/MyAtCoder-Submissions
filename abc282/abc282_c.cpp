#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    rep(i, n){
        if(s[i] == '"'){
            cnt++;
        }else if(s[i] == ','){
            if(cnt % 2 == 0) s[i] = '.';
        }
    }
    rep(i, n) cout << s[i];
    cout << endl;
}
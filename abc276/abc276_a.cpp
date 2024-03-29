#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    int ans = 0;
    rep(i, s.size()){
        if(s[i] == 'a') ans = i+1;
    }
    if(ans == 0){
        cout << "-1" << endl;
    }else{
        cout << ans << endl;
    }
}
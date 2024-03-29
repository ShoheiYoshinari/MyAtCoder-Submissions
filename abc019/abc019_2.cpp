#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    int cnt = 1;
    rep(i, s.size()-1){
        if(s[i] == s[i+1]) cnt++;
        else{
            cout << s[i] << cnt;
            cnt = 1;
        }
    }
    
    cout << s[s.size()-1] << cnt;
    cout << endl;
}
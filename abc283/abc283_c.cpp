#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    int ans = s.size();

    rep(i, s.size()){
        if(s[i] == '0' && i+1 <= s.size()){
            if(s[i+1] == '0') {
                ans--;
                i++;
            }
        }
    }
    cout << ans << endl;
}
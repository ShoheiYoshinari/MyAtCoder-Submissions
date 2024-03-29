#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;
    int num = 0,ans = 0;
    rep(i, n){
        if(s[i] == 'I') num++;
        else num--;
        ans = max(ans ,num);
    }
    cout << ans << endl;
}
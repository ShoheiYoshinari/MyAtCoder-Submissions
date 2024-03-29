#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;

    set<string> s;
    int ans = 0;

    rep(i, n){
        string ss;
        cin >> ss;

        if(s.count(ss) == 0) ans++;
        s.insert(ss);
        reverse(ss.begin(), ss.end());
        s.insert(ss);
    }
    cout << ans << endl;
}
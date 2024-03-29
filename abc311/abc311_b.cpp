#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int cnt = 0, ma = -1;

    rep(i, d){
        bool ans = true;
        rep(j, n){
            if(s[j][i] == 'x') ans = false;
        }
        if(ans)cnt++;
        else cnt = 0;

        ma = max(ma, cnt);
    }
    cout << ma << endl;

}
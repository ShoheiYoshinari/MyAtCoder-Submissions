#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int t;
    cin >> t;
    vector<int> test(t);
    rep(i, t) {
        int n;
        cin >> n;
        int cnt = 0;
        rep(j, n) {
            int a;
            cin >> a;
            if(a % 2 != 0) cnt++;
        }
        test[i] = cnt;
    }
    rep(i, t) cout << test[i] << endl;
}
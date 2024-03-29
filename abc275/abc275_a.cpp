#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, hest = -1, ans = -1;
    cin >> n;
    vector<int> h(n+1);
    rep(i, n) cin >> h[i];
    rep(i, n){
        if(hest < h[i]){
            hest = h[i];
            ans = i;
        }
    }
    cout << ans << endl;

}

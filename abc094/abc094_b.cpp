#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n+1, 0);
    rep(i, m){
        int j;
        cin >> j;
        a[j]++;
    }

    int x1 = 0, x2 = 0;
    for(int i = x; i >= 0; i--){
        x1 += a[i];
    }
    for(int i = x; i <= n; i++){
        x2 += a[i];
    }
    cout << min(x1, x2) << endl;

}
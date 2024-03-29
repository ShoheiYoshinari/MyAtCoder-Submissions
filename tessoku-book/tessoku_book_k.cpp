#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

int n ,x, a[100009];

int binary_search(int x){
    int L = 1, R = n;
    while(L <= R){
        int M = (L + R)/2;
        if(x < a[M]) R = M-1;
        if(x == a[M]) return M;
        if(x > a[M]) L = M+1;
    }
    return -1;
}

int main() {
    cin >> n >> x;
    rep2(i, 1, n) cin >> a[i];
    int ans = binary_search(x);
    cout << ans << endl;
}
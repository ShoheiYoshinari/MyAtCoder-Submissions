#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n, k, a[100009], r[100009];
    long long ans = 0;
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    for(int i = 1; i <= n-1; i++){
        if(i == 1) r[i] = 1;
        r[i] = r[i-1];
        while(r[i] < n && a[r[i]+1] - a[i] <= k){
            r[i] += 1;
        }
    }
    for(int i = 1; i <= n-1; i++){
        ans += r[i]-i;
    }
    cout << ans << endl;
}
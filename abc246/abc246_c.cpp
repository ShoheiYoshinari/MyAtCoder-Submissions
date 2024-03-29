#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];


    long long csum = 0, sum = 0;
    rep(i, n){
        sum += a[i];
        csum += a[i]/x;
        a[i] %= x;
    }

    if(csum >= k){
        sum -= k * x;
        cout << sum << endl;
        return 0;
    }else{
        sum -= csum * x;
        k -= csum;
        sort(a.begin(), a.end());
        for(int i = n-1; i >= 0; i--){
            if(k == 0) break;
            sum -= a[i];
            k--;
        }
        cout << sum << endl;
    }

}
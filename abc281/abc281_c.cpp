#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    long long sum = 0;
    rep(i, n) sum += a[i];

    t %= sum;

    int i = 0;
    for(; i < n; i++){
        if(t - a[i] >= 0){
            t -= a[i];
        }else{
            break;
        }
    }

    cout << i + 1 << " " << t << endl;
}
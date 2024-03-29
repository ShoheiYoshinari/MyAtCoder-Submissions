#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    unsigned long long sum = 0;
    int a[64];
    rep(i, 64) cin >> a[i];

    for(int i = 63; i >= 0; i--){
        sum *= 2;
        sum += a[i];
    }
    cout << sum << endl;

}
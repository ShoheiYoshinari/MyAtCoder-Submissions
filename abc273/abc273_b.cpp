#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    long long x, k;
    cin >> x >> k;
    long long pow10 = 1;


    rep(i, k){
        x /= pow10;
        long long m = x%10;
        if(m <= 4) x -= m;
        else x += 10 - m;
        x *= pow10;
        pow10 *= 10;
    }
    cout << x << endl;
}                               
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a[3];
    rep(i, 3) cin >> a[i];
    sort(a, a+3);
    cout << a[1] << endl;
}
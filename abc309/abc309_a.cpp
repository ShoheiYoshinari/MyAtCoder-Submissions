#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a, b;
    cin >> a >> b;

    bool ans = false;

    if(a == 1 && b == 2 || a == 2 && b == 3) ans = true;
    if(a == 4 && b == 5 || a == 5 && b == 6) ans = true;
    if(a == 7 && b == 8 || a == 8 && b == 9) ans = true;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
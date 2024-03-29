#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int a,b;
    cin >> a >> b;
    if(a * 2 == b || a * 2 + 1 == b || b * 2 == a || b * 2 + 1 == a) cout << "Yes" << endl;
    else cout << "No" << endl;
}
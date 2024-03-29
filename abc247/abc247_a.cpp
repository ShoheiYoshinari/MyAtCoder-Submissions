#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    string s;
    cin >> s;
    string a(4,0);
    a[0] = '0';
    rep(i, 3) a[i] = s[i-1];
    cout << a << endl;

}
    
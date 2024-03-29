#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int x,a,b;
    cin >> x >> a >> b;

    if(b - a >= x+1) cout << "dangerous" << endl;
    else if(b - a <= x && b - a > 0) cout << "safe" << endl;
    else cout << "delicious" << endl;
}
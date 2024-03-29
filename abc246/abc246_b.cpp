#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int a, b;
    cin >> a >> b;
    double d = sqrt(a*a + b*b);
    cout << fixed << setprecision(15) << a/d << " " << b/d << endl;
}
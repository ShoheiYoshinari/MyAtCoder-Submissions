#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    cout << (n / (a + b)) * a + min(a, n %(a + b)) << endl;
}
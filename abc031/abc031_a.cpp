#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int a, d;
    cin >> a >> d;
    if((a+1) * d >= a * (d+1)) cout << (a+1) * d << endl;
    else cout << a * (d+1) << endl;
}
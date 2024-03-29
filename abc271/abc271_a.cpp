#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n, a, b;
    cin >> n;
    a = n/16;
    b  = n%16;
    if(a <= 9) cout << a;
    else cout << (char)('A' + a - 10);
    if(b <= 9) cout << b;
    else cout << (char)('A' + b - 10);

}

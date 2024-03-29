#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;

    if(k % 2 == 0){
        cout << a - b << endl;
    }else{
        cout << b - a << endl;
    }

}
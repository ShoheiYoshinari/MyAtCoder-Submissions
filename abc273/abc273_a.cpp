#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for(int i = n; i > 0; i--){
        ans *= i;
    }
    cout << ans << endl;

}                               
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int sum = 0;
    rep(i, n){
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum << endl;

}

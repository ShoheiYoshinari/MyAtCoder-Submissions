#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    rep(i, n){
        int cnt = (int)(i * 1.08);
        if(cnt == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}
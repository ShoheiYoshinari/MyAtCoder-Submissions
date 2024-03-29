#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool ans = true;
    int cnt = 0;

    while(true){
        rep(i, n){
            if(a[i] & 1){
                ans = false;
            }else{
                a[i] /= 2;
            }
        }
        if(ans) cnt++;
        else{
            cout << cnt << endl;
            return 0;
        }
    }
}
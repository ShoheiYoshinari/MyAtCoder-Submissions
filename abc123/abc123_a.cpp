#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a[5], k;
    rep(i, 5) cin >> a[i];
    cin >> k;

    bool ans = true;
    rep(i, 5){
        rep2(j, i+1, 5){
            if(abs(a[i] - a[j]) > k) ans = false;
        }
    }
    if(ans){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }

}
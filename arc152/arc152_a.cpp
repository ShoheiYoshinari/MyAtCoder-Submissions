#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, l;
    cin >> n >> l;
    int ps = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(a == 1){
            ps += 2;
        }else{
            if(l - ps < 2){
                cout << "No" << endl;
                return 0;
            }
            ps += 3;
        }
    }
    cout << "Yes" << endl;
}
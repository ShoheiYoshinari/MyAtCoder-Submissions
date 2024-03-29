#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n, x;
    cin >> n >> x;
    rep(i, n){
        int a;
        cin >> a;
        if(a == x){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n){
        rep(j, n){
            if(i == 0 && j != 0){
                cout << a[i][j-1];
            }else if(i != 0 && j == n-1){
                cout << a[i-1][j];
            }else if(i == n-1 && j != n-1){
                cout << a[i][j+1];
            }else if(i != n-1 && j == 0){
                cout << a[i+1][j];
            }else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}
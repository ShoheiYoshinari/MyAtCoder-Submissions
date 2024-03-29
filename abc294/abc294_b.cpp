#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h,w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }

    rep(i, h){
        rep(j, w){
            if(a[i][j] == 0){
                cout << '.';
            }else{
                cout << char('A' + a[i][j] - 1); 
            }
        }
        cout << endl;
    }
}
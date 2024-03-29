#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int cnt = 0;

    rep(i, a){
        rep(j, b){
            rep(k, c){
                if(x == i*500 + j*100 + k*50){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
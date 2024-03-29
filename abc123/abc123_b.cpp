#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int a[5];
    rep(i, 5) cin >> a[i];

    int minP10 = 11, tmp = 0;
    int cnt = 0;
    rep(i, 5){
        if(minP10 > a[i]%10 && a[i]%10 != 0){
            tmp = i;
            minP10 = a[i]%10;
        }
    }
    rep(i, 5){
        if(tmp != i){
            if(a[i]%10 != 0){
                cnt += (a[i]/10 + 1) * 10;
            }else{
                cnt += a[i];
            }
        }
    }
    cout << cnt + a[tmp] << endl;
}
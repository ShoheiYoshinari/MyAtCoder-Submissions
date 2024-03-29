#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    rep(i, n){
        rep(j ,n){
            int z = k - i - j;
            if(z >= 1 && z <= n) cnt++;
        }
    }
    cout << cnt << endl;
}
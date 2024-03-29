#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main(){
    int n, a[1009];
    cin >> n;
    rep(i, n) cin >> a[i];

    rep(i, n){
        for(int j = i+1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                if(a[i] + a[j] + a[k] == 1000){
                    cout << "Yes" << endl;
                    return 0;
                }

            }
        }
    }
    cout << "No" << endl;
}
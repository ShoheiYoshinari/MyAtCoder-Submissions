#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    
    long long ans = 0;

    for (int i = 1; i < n; i++) {
        long long x = i, y = n-i;
        long long x_num = 0, y_num = 0;
        for (int j = 1; j*j <= i; j++) {
            if(x % j == 0) {
                x_num++;
                if(x != j*j) x_num++;
            }
        }
        for (int j = 1; j*j <= n-i; j++) {
            if(y % j == 0) {
                y_num++;
                if(y != j*j) y_num++;
            }
        }
        ans += x_num * y_num; 
    }
    cout << ans << endl;
}
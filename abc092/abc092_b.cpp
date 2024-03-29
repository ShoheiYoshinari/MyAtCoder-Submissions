#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;

    rep(i, n){
        int tmp = 0;
        while(1 + tmp * a[i] <= d){
            tmp++;
            sum++;
        }
    }
    cout << sum + x << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int dist = -1;

    rep(i, n){
        if(a[i+1] - a[i] > dist){
            dist = a[i+1] - a[i];
        }
    }
    if(a[0] + k - a[n-1] > dist) dist = a[0] + k - a[n-1];
    cout << k - dist << endl;

}
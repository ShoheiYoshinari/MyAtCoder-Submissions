#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int a[3*n];
    rep(i, 3*n) cin >> a[i];

    map<int,int> mp;
    rep(i, 3*n){
        mp[a[i]]++;
        if(mp[a[i]] == 2) {
            cout << a[i] << ' ';
        }
    }
    cout << endl;
}
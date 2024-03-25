#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int num;
int a[100009], n[100009];

int main(){
    cin >> num;
    rep(i, num) cin >> a[i];

    rep(i, num){
        n[a[i]]++;
        n[a[i]+1]++;
        n[a[i]+2]++;
    }
    int mx = -1;
    rep(i, 100005) mx = max(mx, n[i]);
    cout << mx << endl;
    return 0;
}
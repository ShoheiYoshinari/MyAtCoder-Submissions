#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;

    vector<int> a(n), copy(n);
    rep(i, n){
        cin >> a[i];
        copy[i] = a[i];
    }
    sort(copy.begin(), copy.end());
    rep(i, n){
        if(copy[n-1] != a[i]){
            cout << copy[n-1] << endl;
        }else{
            cout << copy[n-2] << endl;
        }
    }
    cout << endl;

}
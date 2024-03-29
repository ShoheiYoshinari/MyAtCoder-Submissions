#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n ,ans = -1;
    cin >> n;
    vector<string> s(n+1);
    vector<int> a(n+1);

    rep(i, n) cin >> s[i] >> a[i];
    int m = 1000000009;
    rep(i, n){
        if(m > a[i]){
            m = a[i];
            ans = i;
        } 
    }
    for(int i = ans; i < n+ans; i++){
        cout << s[i%n] << endl;
    }
}
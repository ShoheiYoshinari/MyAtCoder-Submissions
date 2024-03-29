#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    vector<double> l(n), r(n);
    rep(i, n) cin >> t[i] >> l[i] >> r[i];

    long long ans = 0;

    rep(i, n){
        if(t[i] == 2){
            r[i] -= 0.1;
        }else if(t[i] == 3){
            l[i] += 0.1;
        }else if(t[i] == 4){
            l[i] += 0.1;
            r[i] -= 0.1;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(max(l[i],l[j]) <= min(r[i],r[j])) ans++;
        } 
    }
    cout << ans << endl;
}
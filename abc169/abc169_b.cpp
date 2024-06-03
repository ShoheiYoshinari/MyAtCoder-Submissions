#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

ll p18 = 1;

int main(){
    rep2(i, 0, 18) p18 *= 10;
    int n;
    cin >> n;
    vector<ll> a(n);
    bool none = false;
    rep(i, n){
        cin >> a[i];
        if(a[i] == 0) none = true;
    }

    if(none){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep2(i, 0, n){
        if(p18/a[i] < ans){
            cout << -1 << endl;
            return 0;
        }else{
            ans *= a[i];
        }
    }
    cout << ans << endl;
    return 0;

}
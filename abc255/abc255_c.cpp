#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i <= (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

ll x, a, d, n;

int main(){
    cin >> x >> a >> d >> n;

    if(d < 0){
        ll fi = a + d*(n-1);
        a = fi;
        d *= -1;
    }

    ll st = a;
    ll fi = a + d*(n-1);
    if(st <= x && x <= fi){
        ll m;
        if(d != 0) m = (x-st)%d;
        else m = 0;
        cout << min(m, d-m) << endl;
    }else if(x < st){
        cout << st - x << endl;
    }else{
        cout << x - fi << endl;
    }
    return 0;
}
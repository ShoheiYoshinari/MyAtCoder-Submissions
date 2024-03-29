#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
long long  n, k, tmp;
set<long long> a;

int main(){
    cin >> n >> k;
    rep(i, n){
        cin >> tmp;
        if(tmp <= k) a.insert(tmp);
    }

    long long cnt = 0;

    rep2(i, 1, k){
        cnt += i;
    }
    for(auto p : a){
        cnt -= p;
    }
    cout << cnt << endl;
    return 0;


}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    long long n;
    cin >> n;
    vector<int> a;
    rep(i, 60){
        if(n & (1ll<<i)) a.push_back(i);
    }
    vector<long long> res;
    int k = a.size();
    rep(i, (1<<k)){
        long long cur = 0;
        rep(j, k){
            if(i & (1<<j)) cur |= 1ll<<a[j];
        }
        res.push_back(cur);
    }
    for(auto &x : res) cout << x << endl;

} 
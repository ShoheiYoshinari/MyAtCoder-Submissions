#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    rep(i, n){
        int x;
        cin >> x;
        a[x]++;
    }
    vector<int> k(n, 0);
    int t = 1;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        k[a.size() - t] = (*itr).second;
        t++;
    }
    rep(i, n) cout << k[i] << endl;
    
}
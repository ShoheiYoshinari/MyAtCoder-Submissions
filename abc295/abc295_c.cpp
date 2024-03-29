#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    int cnt = 0;
    
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }

    for(auto [_, i] : mp) cnt += i / 2;
    cout << cnt << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = -1, hp;
    //ある料理に対して何回回したら喜ぶかをcntに格納する
    vector<int> cnt(n, 0);
    rep(i, n){
        hp = p[i] - i;
        cnt[(hp - 1 + n)%n]++;
        cnt[(hp + n)%n]++;
        cnt[(hp + 1 + n)%n]++;
    }
    rep(i, n){
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
}  
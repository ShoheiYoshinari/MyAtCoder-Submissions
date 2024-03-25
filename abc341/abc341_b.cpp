#include <bits/stdc++.h>
using namespace std;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

long long n, a[200009], t[200009], s[200009];

int main(){
    cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n) cin >> s[i] >> t[i];

    rep(i, 1, n) a[i+1] += a[i]/s[i] * t[i];

    cout << a[n] << endl;
    return 0;
}
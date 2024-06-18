#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m);

    rep(i, n) {
        int tmp; cin >> tmp;
        a.insert(tmp);
    }
    rep(i, m) {
        cin >> b[i];
    }

    sort(all(b));

    bool ok = true;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        auto it = a.lower_bound(b[i]);
        if(it == a.end()) {
            ok = false;
            break;
        } else {
            sum += *it;
            a.erase(it);
        }
    }

    cout << (ok ? sum : -1) << endl;
    return 0;
}

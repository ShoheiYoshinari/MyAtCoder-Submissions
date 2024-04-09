#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

long long n;
vector<long long> a, s;

int main(){
    cin >> n;
    rep(i, n){
        long long x;
        cin >> x;
        a.push_back(x);
        s.push_back(x);
    }

    sort(all(s));

    long long ss[n];
    ss[0] = 0;
    rep2(i, 1, n+1) {
        ss[i] = ss[i-1] + s[i-1];
    }

    rep(i, n){
        auto pos = upper_bound(all(s), a[i]) - s.begin();
        cout << ss[n] - ss[pos] << ' ';
    }
    cout << endl;
    return 0;
}
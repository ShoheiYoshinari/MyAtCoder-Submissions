#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n;

int main(){
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> a;
    rep(i, n) a.push_back(i+1);

    int cnt = 1; 
    int s, t;
    do{
        bool okp = true, okq = true;
        rep(i, n){
            if(p[i] != a[i]) okp = false;
            if(q[i] != a[i]) okq = false;
        }
        if(okp) s = cnt;
        if(okq) t = cnt;

        cnt++;
    }while(next_permutation(all(a)));

    cout << abs(s - t) << endl;
    return 0;
}
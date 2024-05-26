#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    rep(i, t) cin >> a[i];

    int tate[n], yoko[n], naname[2];
    rep(i, n) tate[i] = 0, yoko[i] = 0;
    naname[0] = 0, naname[1] = 0;
    rep(i, t){
        bool ok = false;
        a[i]--;
        int x = a[i]/n;
        int y = a[i]%n;

        tate[x]++;
        if(tate[x] == n) ok = true;
        yoko[y]++;
        if(yoko[y] == n) ok = true;
        if(x == y) naname[0]++;
        if(naname[0] == n) ok = true;
        if(x+y == n-1) naname[1]++;
        if(naname[1] == n) ok = true;

        if(ok){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
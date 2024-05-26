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
    int n ,m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n+m);
    rep(i, n) cin >> a[i], c[i] = a[i];
    rep(i, m) cin >> b[i], c[n+i] = b[i];
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    rep(i, n+m-1){
        if(find(a.begin(), a.end(), c[i]) != a.end() && find(a.begin(), a.end(), c[i+1]) != a.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
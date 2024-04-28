#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

using ll = long long;

int main(){
    char a[109][109], b[109][109];
    int n;

    cin >> n;
    rep(i, n){
        rep(j, n) cin >> a[i][j];
    }
    rep(i, n){
        rep(j, n) cin >> b[i][j];
    }

    rep(i, n){
        rep(j, n){
            if(a[i][j] != b[i][j]){
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
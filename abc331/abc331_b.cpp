#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, s, m, l;

int main(){
    cin >> n >> s >> m >> l;

    int ans = 100000000;

    rep(i, 100){
        rep(j, 100){
            rep(k, 100){
                if(i*6 + j*8 + k*12 >= n){
                    ans = min(ans, i*s + j*m + k*l);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n;
int x[109], y[109];

int main(){
    cin >> n;
    rep2(i, 1, n) cin >> x[i] >> y[i];

    rep2(i, 1, n){
        int length = -1;
        int ans;
        rep2(j, 1, n){
            int now = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(now > length){
                ans = j;
                length = now;
            }
        }
        cout << ans << endl;
    }
    cout << endl;
    return 0;
}
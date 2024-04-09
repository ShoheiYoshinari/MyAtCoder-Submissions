#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, s, k;
int p[109],  q[109];

int main(){
    cin >> n >> s >> k;
    rep(i, n){
        cin >> p[i] >> q[i];
    }
    int sm = 0;
    rep(i, n) sm += p[i] * q[i];

    if(sm < s) sm += k;

    cout << sm << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n, k;
    cin >> n >> k;
    int a[109];
    rep(i, n) cin >> a[i];

    int cnt = 1;
    int pos = 0;
    int sa = 0;
    while(n != pos){
        sa += a[pos];
        pos++;
        if(k - sa < a[pos]){
            cnt++;
            sa = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
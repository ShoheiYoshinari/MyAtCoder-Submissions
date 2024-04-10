#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    long long n;
    cin >> n;
    vector<int> a;
    rep(i, n){
        int aa;
        cin >> aa;
        a.push_back(aa);
    }

    long long ans = 0;
    long long sum = 0;
    rep(i, n){
        sum += a[i];
        ans = min(ans, sum);
    }

    if(ans < 0) cout << abs(ans) + sum << endl;
    else cout << ans + sum << endl;

    return 0;
}
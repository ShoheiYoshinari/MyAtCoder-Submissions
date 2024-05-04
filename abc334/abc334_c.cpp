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

int n, k;

int main(){
    cin >> n >> k;
    vector<int> a(k);
    vector<int> socks;
    rep(i, k){
        cin >> a[i];
    }
    int pos = 0;
    rep(i, n){
        socks.push_back(i+1);
        if(i+1 == a[pos]){
            pos++;
            continue;
        }
        socks.push_back(i+1);
    }

    vector<int> diff, difl;
    int sum = 0;
    rep2(i, 1, socks.size()){
        diff.push_back(socks[i] - socks[i-1]);
        i++;
    }
    for(int i = socks.size()-1; i >= 1; i--){
        difl.push_back(abs(socks[i] - socks[i-1]));
        i--;
    }

    int dpf[diff.size()+1], dpl[difl.size()+1];
    dpf[0] = 0; dpl[0] = 0;

    rep2(i, 1, diff.size()+1) dpf[i] = dpf[i-1] + diff[i-1];
    rep2(i, 1, difl.size()+1) dpl[i] = dpl[i-1] + difl[i-1];

    int ans = dpf[diff.size()];
    rep(i, diff.size()+1){
        ans = min(ans, dpf[i] + dpl[diff.size()-i]);
    }
    cout << ans << endl;
    return 0;

}
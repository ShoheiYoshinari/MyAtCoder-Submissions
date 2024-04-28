#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
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
    int n;
    cin >> n;
    int a[n+1];
    rep2(i, 1, n){
        cin >> a[i];
    }

    vector<pair<int, int>> chang;
    rep2(i, 1, n){
        while(a[i] != i){
            int j = a[i];
            swap(a[i], a[j]);
            chang.emplace_back(i, j);
        }
    }
    cout << chang.size() << endl;
    for(auto [i, j] : chang) cout << i << ' ' << j << endl;
    return 0;
}
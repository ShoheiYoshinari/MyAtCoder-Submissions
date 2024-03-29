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
    int n, k;
    int t[9][9];
    cin >> n >> k;
    rep(i, n){
        rep(j, n) cin >> t[i][j];
    }

    vector<int> idx;
    rep2(i, 1, n) idx.push_back(i);

    int ans = 0;
    do{
        int time = 0;
        rep(i, n){
            time += t[idx[i]][idx[(i+1)%n]];
        }
        if(time == k) ans++;


    }while(next_permutation(all(idx)));
    cout << ans << endl;
    return 0;


}

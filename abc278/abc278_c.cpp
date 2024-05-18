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
    int n, q;
    cin >> n >> q;
    set<pair<int, int> > follow;
    rep(i, q){
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1){
            follow.emplace(a, b);
        }else if(t == 2){
            follow.erase({a, b});
        }else if(t == 3){
            cout << (follow.count({a, b}) && follow.count({b, a}) ? "Yes" : "No") << endl;
        }
    }
}
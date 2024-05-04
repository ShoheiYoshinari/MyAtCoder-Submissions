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

int n, x, t, s;
int sm = 0;

int main(){
    cin >> n >> x;
    vector<int> v, p;
    rep(i, n){
        cin >> t >> s;
        v.push_back(t); p.push_back(s);
    }

    rep(i, n){
        sm +=  v[i] * p[i];
        if(sm > x * 100){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, a, b;

int main(){
    cin >> n >> a >> b;
    int week = a + b;
    vector<int> d(n);

    rep(i, n){
        cin >> d[i];
        d[i] %= week;
    }
    sort(all(d));
    rep(i, n) d.push_back(d[i] + week);
    rep(i, d.size()-1){
        if(d[i+1] - d[i] >= b+1){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n;
int x[9], y[9];

int main(){
    cin >> n;
    rep(i, n) cin >> x[i] >> y[i];

    vector<int> root;
    rep(i, n) root.push_back(i);

    int ans = 0;
    double distance = 0;
    do{
        rep(i, n-1){
            distance += sqrt((x[root[i]] - x[root[i+1]])*(x[root[i]] - x[root[i+1]]) 
                      + (y[root[i]] - y[root[i+1]])*(y[root[i]] - y[root[i+1]]));
        }
    }while(next_permutation(all(root)));

    int wari = 1;
    rep(i, n) wari *= i+1;

    cout << fixed << setprecision(10) << distance / wari << endl;
    return 0;

}
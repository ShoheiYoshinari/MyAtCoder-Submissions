#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n){
        cin >> a[i+1];
    }
    
    ll cnt = 0;
    ll res = 0;

    rep2(i, 1, n){
        int j = a[i];
        if(a[j] == i && i < j) cnt++;
        else if(j == i) res++;
    }
    cnt += res*(res-1)/2;
    cout << cnt << endl;
    return 0;
}
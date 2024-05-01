#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, k;
vector<int> a;

bool isOK(ll index, ll key){
    if(index >= key) return true;
    else return false;
}

ll check(ll index){
    ll sum = 0;
    rep(i, n) sum += index / a[i];
    return sum;
}

ll Binary_search(ll key){
    ll ng = -1;
    ll ok = 1000000000;

    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        ll sum = check(mid);
        
        if(isOK(sum, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> k;
    int t;
    rep(i, n){
        cin >> t;
        a.push_back(t);
    }
    cout << Binary_search(k) << endl;
    return 0;


}
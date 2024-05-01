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

int n, x;
vector<int> a;

bool isOK(int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int Binary_search(int key){
    int ng = -1;
    int ok = (int)a.size();

    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;

        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> x;
    int t;
    rep(i, n){
        cin >> t;
        a.push_back(t);
    }
    cout << Binary_search(x) + 1 << endl;
    return 0;
}


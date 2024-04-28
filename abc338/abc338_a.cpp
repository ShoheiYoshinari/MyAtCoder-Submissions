#include <bits/stdc++.h>
using namespace std;
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

using ll = long long;

int main(){
    string s;
    cin >> s;
    bool ok = true;
    if(s[0] < 'A' || s[0] > 'Z') ok = false;
    rep2(i, 1, s.size()){
        if(s[i] < 'a' || s[i] > 'z') ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
    
}
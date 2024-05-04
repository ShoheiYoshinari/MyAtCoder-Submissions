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

int n, k, t;

int main(){
    cin >> n >> k;
    vector<int> p;
    int ck[n+1];
    rep(i, n){
        cin >> t;
        p.push_back(t);
        ck[t] = i;
    }

    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    set<int> st;
    rep(i, k) st.insert(ck[i+1]);
    auto minIte = st.begin();
    auto maxIte = st.end();
    maxIte--;
    int ans = *maxIte - *minIte;
    rep(i, n-k){
        st.erase(ck[i+1]);
        st.insert(ck[i+k+1]);
        minIte = st.begin();
        maxIte = st.end();
        maxIte--;
        ans = min(ans, *maxIte - *minIte);
    }
    cout << ans << endl;
    return 0;



}
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

int n, m;

vector<bool> seen;
set<int> st;
ll cnt;
void dfs(const Graph &G, int v){
    seen[v] = true;
    st.insert(v);
    for(auto e : G[v]){
        if(!seen[e]) dfs(G, e);
    }
}
int main(){
    cin >> n >> m;
    Graph G(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, false);
    ll link = -m;
    rep(i, n){
        if(!seen[i]){
            st.clear();
            dfs(G, i);
            ll cnt = st.size();
            link += ll(cnt*(cnt-1)/2);
        }
    }
    cout << link << endl;
    return 0;
}
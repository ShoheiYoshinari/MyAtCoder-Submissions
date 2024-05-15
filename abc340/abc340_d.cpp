#include<bits/stdc++.h>
using namespace std;
#define rep(i, s) for(int i = 0; i < (int)s; i++)
#define rep2(s, v, t) for(int s = (int)v; s <= (int)t; s++)
using ll = long long;

ll n;
ll a[200009], b[200009], x[200009];
vector<pair<ll, ll> > G[200009];

ll cur[200009]; bool ok[200009];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q;

int main(){
    cin >> n;
    rep2(i, 1, n-1){
        cin >> a[i] >> b[i] >> x[i];
        G[i].push_back(make_pair(i+1, a[i]));
        G[i].push_back(make_pair(x[i], b[i]));
    }

    rep2(i, 1, n) ok[i] = false;
    rep2(i, 1, n) cur[i] = 1000000000000000000ll;

    cur[1] = 0;
    Q.push(make_pair(cur[1], 1));

    while(!Q.empty()){
        ll pos = Q.top().second; Q.pop();

        if(ok[pos] == true) continue;

        ok[pos] = true;
        rep(i, G[pos].size()){
            int nex = G[pos][i].first;
            int cost = G[pos][i].second;
            if(cur[nex] > cur[pos] + cost){
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex], nex));
            }
        }
    }

    cout << cur[n] << endl;

    return 0;


}
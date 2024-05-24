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
    int n, m;
    cin >> n >> m;
    int a[m];
    string s[n];
    rep(i, m) cin >> a[i];
    rep(i, n) cin >> s[i];

    vector<pair<int, int> > q;
    rep(i, m) q.emplace_back(a[i], i);
    sort(all(q));
    reverse(all(q));

    int p[n];
    int max_p = -1;
    rep(i, n){
        int cnt = 0;
        rep(j, m){
            if(s[i][j] == 'o') cnt += a[j];
        }
        p[i] = cnt;
        p[i] += i+1;
        max_p = max(max_p, p[i]);
    }

    rep(i, n){
        int ans = 0;
        int pos = 0;
        while(true){
            if(p[i] < max_p){
                if(s[i][q[pos].second] == 'x'){
                    p[i] += q[pos].first;
                    ans++;
                }
            }else{
                cout << ans << endl;
                break;
            }
            pos++;
        }
    }
    return 0;
}
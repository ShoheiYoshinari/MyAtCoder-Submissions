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

int n, m, c;
string s;
char ss;

int main(){
    cin >> n >> m;
    vector<int> st[m];
    vector<int> col;
    cin >> s;
    rep(i, n){
        cin >> c;
        c--;
        col.push_back(c);
        st[c].push_back(i);
    }

    rep(i, m){
        int tar = st[i][st[i].size()-1];
        st[i].insert(st[i].begin(), tar);
    }

    vector<int> pos(m, 0);

    rep(i, n){
        int tmp = st[col[i]][pos[col[i]]];
        cout << s[tmp];
        pos[col[i]]++;
    }
    cout << endl;
}
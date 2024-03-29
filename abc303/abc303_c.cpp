#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int,int>> p;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        p.insert({a, b});
    }

    int x = 0, y = 0;
    bool ans = true;
    rep(i, s.size()){
        if(s[i] == 'R')x++;
        if(s[i] == 'L')x--;
        if(s[i] == 'U')y++;
        if(s[i] == 'D')y--;
        h--;

        if(h < 0){
            ans = false;
            break;
        }else if(p.find(make_pair(x, y)) != p.end()){
            if(h < k) {
                h = k;
                p.erase(make_pair(x, y));
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
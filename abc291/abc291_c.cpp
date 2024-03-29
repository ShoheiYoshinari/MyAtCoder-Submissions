#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    bool ans = true;
    set<pair<int,int>> p;
    int x = 0,y = 0;
    p.insert(make_pair(0,0));
    rep(i, n){
        if(s[i] == 'R') x++;
        if(s[i] == 'L') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;

        if(p.find(make_pair(x,y)) == p.end()){
            p.insert(make_pair(x, y));
        }else{
            ans = false;
        }
    } 
    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}
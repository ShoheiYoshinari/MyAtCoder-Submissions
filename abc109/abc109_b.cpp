#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;

    bool ans = true;

    set<string> s;
    char connect;
    string f;
    cin >> f;
    connect = f[f.size()-1];
    s.insert(f);

    rep(i, n-1){
        string w;
        cin >> w;
        if(w[0] != connect){
            ans = false;
        }else{
            connect = w[w.size()-1];
        }
        if(s.find(w) != s.end()){
            ans = false;
        }else{
            s.insert(w);
        }
    }
    if(ans) cout << "Yes" <<endl;
    else cout << "No" << endl;
}
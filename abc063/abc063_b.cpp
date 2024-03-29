#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    set<char> cnt;
    rep(i, s.size()){
        cnt.insert(s[i]);
    }
    if(cnt.size() == s.size()) cout << "yes" << endl;
    else cout << "no" << endl;
}
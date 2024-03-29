#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    bool ans = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(s[i] == s[j]) ans = false;
        }
    }
    string s1 = "HDCS";
    string s2 = "A23456789TJQK";
    for(int i = 0; i < n; i++){
        if(!count(s1.begin(), s1.end(), s[i][0]) || !count(s2.begin(), s2.end(), s[i][1])){
            ans = false;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}


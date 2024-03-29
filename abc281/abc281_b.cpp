#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    
    bool ans = true;

    if(s.size() != 8) ans = false;

    if(s[0] < 'A' || s[0] > 'Z') ans = false;

    if(s[1] < '1' || s[1] > '9') ans = false;

    for(int i = 2; i <= 6; i++){
        if(s[i] < '0' || s[i] > '9') ans = false;
    }

    if(s[s.size()-1] < 'A' || s[s.size()-1] > 'Z') ans = false;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

}
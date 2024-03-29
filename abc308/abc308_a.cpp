#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    vector<int> s(8);
    rep(i, 8) cin >> s[i];
    rep(i, 8){
        if(s[i] < 100 || s[i] > 675){
            cout << "No" << endl;
            return 0;
        }
        if(s[i]%25 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, 7){
        if(s[i+1] < s[i]){
            cout << "No" << endl;
            return 0;
        } 
    }
    cout << "Yes" << endl;
}
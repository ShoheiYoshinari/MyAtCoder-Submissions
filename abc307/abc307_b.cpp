#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i, n){
        string tmp = s[i];
        rep(j, n){
            if(i != j){
                tmp += s[j];
                bool ans = true;
                rep(k, tmp.size()){
                    if(tmp[k] != tmp[tmp.size()-k-1]){
                        ans = false;
                        break;
                    }
                }
                if(ans){
                    cout << "Yes" << endl;
                    return 0;
                }
                tmp = s[i];
            }
        }
    }
    cout << "No" << endl;
} 
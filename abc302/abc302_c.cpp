#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    sort(s.begin(), s.end());
    do{
        bool ans = true;
        rep(i, n-1){
            int cnt = 0;
            rep(j, m){
                if(s[i][j] != s[i+1][j]) cnt++;
            }   
            if(cnt != 1) ans = false;
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << "No" << endl;
}
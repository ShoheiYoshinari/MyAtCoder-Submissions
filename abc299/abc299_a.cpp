#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    bool ans = false;
    rep(i, n){
        if(s[i] == '|'){
            if(cnt == 0) cnt++;
            else if(cnt == 1) break;
        }else if(s[i] == '*'){
            if(cnt == 1) {
                cout << "in" << endl;
                return 0;
            }
        }

    }
    cout << "out" << endl;

}
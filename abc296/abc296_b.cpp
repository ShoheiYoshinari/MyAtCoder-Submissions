#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    char ans1;
    int ans2;
    rep(i, 8){
        string s;
        cin >> s;
        rep(j, 8){
            if(s[j] == '*') {
                ans1 = char('a' + j);
                ans2 = 8 - i;
                break;
            }

        }
    }
    cout << ans1 << ans2 << endl;

}

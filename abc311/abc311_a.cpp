#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool ans1 = false, ans2 = false, ans3 = false;

    rep(i, n){
        if(s[i] == 'A') ans1 = true;
        if(s[i] == 'B') ans2 = true;
        if(s[i] == 'C') ans3 = true;

        if(ans1 & ans2 & ans3){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << endl;
}
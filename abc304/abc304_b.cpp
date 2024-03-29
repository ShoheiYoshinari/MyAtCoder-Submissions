#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    if(s.size() <= 3){
        cout << s << endl;
    }else{
        rep(i,3){
            cout << s[i];
        }
        rep(i, s.size()-3){
            cout << '0';
        }
    }
    cout << endl;

}
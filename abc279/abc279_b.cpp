#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s,t;
    cin >> s >> t;

    int sl = s.size(), tl = t.size();
    for(int i = 0; i < sl-tl+1; i++){
        string cur;
        for(int j = 0; j < tl; j++){
            cur.push_back(s[i+j]);
        }
        if(cur == t){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
}
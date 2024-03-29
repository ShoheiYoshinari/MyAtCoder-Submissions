#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int deep = 0;
    vector<string> d(s.size()+1);
    rep(i, s.size()){
        if(s[i] >= 'a' && s[i] <= 'z') d[deep] += s[i];

        if(s[i] == '('){
            deep++;
            d[deep] += s[i];
        }else if(s[i] == ')'){
            d[deep] += s[i];
            if(deep > 0){
                d[deep] = "";
                deep--;
            }
        }
    }
    rep(i, deep+1){
        cout << d[i];
    }
    cout << endl;
}
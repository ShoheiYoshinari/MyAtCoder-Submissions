#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int t = 0, a = 0;
    string s;
    cin >> s;
    rep(i, n){
        if(s[i] == 'T'){
            t++;
        }else{
            a++;
        }
    }
    if(t > a) cout << 'T' << endl;
    else if(t < a) cout << 'A' << endl;
    else if(t == a){
        if(s[n-1] == 'T') cout << 'A' << endl;
        else cout << 'T' << endl;
    }
}
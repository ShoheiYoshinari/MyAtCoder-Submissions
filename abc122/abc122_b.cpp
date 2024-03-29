#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    string s;
    cin >> s;

    int maxAns = -1, tmp =0;
    rep(i, s.size()){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            tmp++;
        }else{
            tmp = 0;
        }
        maxAns = max(maxAns, tmp);
    }
    cout << maxAns << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s,t;
    cin >> s >> t;
    
    int sfree = 0 ,tfree = 0;
    vector<int> ss(28),tt(28);

    rep(i, s.size()){
        if(s[i] == '@'){
            sfree++;
        }else{
            ss[(s[i] - 'a')]++;
        }
    }
    rep(i, t.size()){
        if(t[i] == '@'){
            tfree++;
        }else{
            tt[(t[i] - 'a')]++;
        }
    }

    int dif = 0;

    rep(i, 28){
        dif +=  abs(ss[i] - tt[i]);
        if(abs(ss[i]-tt[i]) > 0){
            if(char('a' + i) != 'a' && char('a' + i) != 't' && char('a' + i) != 'c' && char('a' + i) != 'o' && char('a' + i) != 'd' && char('a' + i) != 'e' && char('a' + i) != 'r'){
                cout << "No" <<endl;
                return 0;
            }
        }
    }
    if(dif <= abs(sfree + tfree)) cout << "Yes" << endl;
    else cout << "No" <<endl;
}
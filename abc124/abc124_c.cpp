#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;

    char crt = s[0];
    int cnt = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == crt){
            cnt++;
            if(s[i] == '1') crt  = '0';
            else crt = '1';            
        }else{
            crt = s[i];
        }
    }
    cout << cnt << endl;
}
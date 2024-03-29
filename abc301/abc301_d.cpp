#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long kto10(string t){
    long long num = 0;
    for(int i = 0; i < t.length(); i++){
        num = num * 2 + (t[i] - '0');
    }
    return num;
}

int main(){
    string s;
    long long n;
    cin >> s >> n;

    for(int i = 0; i < s.length(); i++){
        string t = s;
        if(s[i] == '?'){
            t[i] = '1';
            for(int j = i+1; j < s.length(); j++){
                if(s[j] == '?'){
                    t[j] = '0';
                }
            }
            if(n >=  kto10(t)){
                s[i] = '1';
            }else{
                s[i] = '0';
            }
        }
    }
    long long ans = kto10(s);
    if(n >= ans){
        cout << ans << endl;
    }else{
        cout << "-1" << endl;
    }
}
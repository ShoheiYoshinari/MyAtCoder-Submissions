#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
int main() {
    string s;
    cin >> s;

    vector<int> ku;
    vector<char> alfa;

    rep(i, s.size()){
        if(s[i] == '('){
            ku.push_back(i);
        }else if(s[i] == ')'){
            int last = ku.back();
            for (int j = last; j < i; j++)
            {
                if(s[j] >= 'a' && s[j] <= 'z'){
                    alfa.erase(s[j]);
                }
            }
            ku.erase(ku.end()-1);
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            if(alfa.find(s[i]) != alfa.end()){
                cout << "No" << endl;
                return 0;
            }else{
                alfa.push_back(a[i]);
            }
        }
    }
    cout << "Yes" << endl;
}
*/

int main(){
    string s;
    cin >> s;

    for (char i = 'a'; i < 'z'; i++){
        int cnt = 0;
        int dep = 0;
        vector<int> cnt_d(s.size());
        cnt_d[0] = 0;
        rep(j, s.size()){
            if(s[j] == '('){
                dep++;
                cnt_d[dep] = 0;
            }else if(s[j] == ')'){
                cnt -= cnt_d[dep];
                cnt_d[dep] = 0;
                dep--;
            }if(s[j] == i){
                if(cnt > 0){
                    cout << "No" <<endl;
                    return 0;
                }else{
                    cnt++;
                    cnt_d[dep]++;
                }
            }
        }
    }
    cout << "Yes" << endl;
} 
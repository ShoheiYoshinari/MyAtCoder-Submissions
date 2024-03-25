#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

string s;
int main(){
    cin >> s;
    bool ok1 = false, ok2 = false;
    int cnt1 = 0, cnt2 = 0;
    rep(i, s.size()){
        if(s[i] == '<'){
            if(cnt1 == 0){
                ok1 = true;
                cnt1++;
            }else{
                ok1 = false;
            }
        }
        if(s[i] == '>'){
            if(cnt2 == 0){
                ok2 = true;
                cnt2++;
            }else{
                ok2 = false;
            }
        }
    }
    if(ok1 && ok2) cout << "Yes" << endl;
    else cout << "No" << endl;

}
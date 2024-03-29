#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;

    bool ans1 = false,ans2 = false;
    int preB = 0,cntB = 0,cntK = 0;

    rep(i, s.size()){
        if(s[i] == 'B'){
            if(cntB == 0){
                preB = (i+1) % 2;
                cntB++;
            }else if(cntB == 1){
                if(preB != (i+1) % 2){
                    ans1 = true;
                }
            }           
        }

        if(cntK == 0 && s[i] == 'R'){
            cntK++;
        }else if(cntK == 1 && s[i] == 'K'){
            cntK++;
        }else if(cntK == 2 && s[i] == 'R'){
            ans2 = true;
        }
        
    }     
    if(ans1 == true && ans2 == true) cout<< "Yes" << endl;
    else cout << "No" <<endl; 
}
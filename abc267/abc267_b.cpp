#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    vector<int> f(7);
    f[0] = (s[6] == '1');
    f[1] = (s[3] == '1');
    f[2] = ((s[7] == '1') | (s[1] == '1'));
    f[3] = ((s[4] == '1') | (s[0] == '1'));
    f[4] = ((s[8] == '1') | (s[2] == '1'));
    f[5] = (s[5] == '1');
    f[6] = (s[9] == '1');

    if(s[0] == '0'){
        rep(i, 7-2){
            if(f[i] == 1 && f[i+1] == 0){
                int k = 1;
                while(i+k != 6){
                    if(f[i+k] == 0) k++;
                    if(f[i+k] == 1){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h, w;
    cin >> h >> w;
    char c[h][w];
    rep(i, h){
        rep(j, w) cin >> c[i][j];
    }
    vector<int> ans(min(h, w)+1);

    rep(i, h){
        rep(j, w){
            if(c[i][j] == '#'){
                int num = 1; 
                while(true){
                    if(c[i+num][j+num] == '#' && c[i-num][j+num] == '#' && c[i+num][j-num] == '#' && c[i-num][j-num] == '#'){
                        num++;
                    }else{
                        ans[num-1]++;
                        break;
                    }
                }
            }
        }
    }
    
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
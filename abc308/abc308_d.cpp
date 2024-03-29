#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

string snuke = "snuke";
int h, w;

// 上下左右の移動
int diff_x[4] = {1, 0, -1, 0};
int diff_y[4] = {0, 1, 0, -1};

vector<string> s(501);
//　到達したらtrueにする
vector<vector<bool>> seen(501, vector<bool>(501, false));

void dfs(int x, int y, int index){
    seen[x][y] = true;
    int next = (index + 1) % 5;

    for(int k = 0; k < 4; k++){
        int ni = x + diff_x[k];
        int nj = y + diff_y[k];
        // マスの範囲内であるか
        if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        // このマスは未到達であるか
        if(seen[ni][nj]) continue;
        // このマスはsnukeになるように続くか
        if(s[ni][nj] == snuke[next]){
            // 次のマスで再帰的に繰り返す
            dfs(ni, nj, next);
        }
    }
}
int main(){
    cin >> h >> w;
    rep(i, h) cin >> s[i];

    if(s[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }
    dfs(0, 0, 0);

    if(seen[h-1][w-1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;



}
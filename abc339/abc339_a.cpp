#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

string s;

int main(){
    cin >> s;

    string ans;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '.') break;
        else ans += s[i];
    }
    
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
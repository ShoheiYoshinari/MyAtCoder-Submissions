#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

string s;

int main(){
    cin >> s;
    map<char, int> mp;
    rep(i, s.size()) mp[s[i]]++;

    

    int ans = 0;
    char a;
    for(auto p : mp){
        if(ans < p.second){
            ans = p.second;
            a = p.first;
        }
    }

    cout << a << endl;
    return 0;
}
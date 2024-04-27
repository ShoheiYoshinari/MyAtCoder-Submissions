#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

using ll = long long;

int main(){
    int n;
    vector<int> a;

    int now;
    
    cin >> n;
    rep(i, n){
        cin >> now;
        a.push_back(now);
        while(true){
            bool flag = false;
            int size = a.size();
            if(size >= 2 && a[a.size()-2] == a[a.size()-1]){
                a.pop_back();
                a[a.size()-1]++;
                flag = true;
            }
            if(!flag) break;
        }
    }
    
    cout << a.size() << endl;
    return 0;
}
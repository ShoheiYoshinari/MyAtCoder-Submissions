#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int a, b;

int main(){
    cin >> a >> b;
    if(a > 0 && b == 0) cout << "Gold" << endl;
    else if(a == 0 && b > 0) cout << "Silver" << endl;
    else if(a > 0 && b > 0) cout << "Alloy" << endl;

    return 0;
}
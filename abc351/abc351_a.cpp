#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
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
    int a[10], b[10];
    int suma = 0, sumb = 0;
    rep(i, 9){
        cin >> a[i];
        suma += a[i];
    }
    rep(i, 8){
        cin >> b[i];
        sumb += b[i];
    }
    if(sumb == suma) cout << 1 << endl;
    else cout << suma - sumb + 1 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

long long x, k, d;

int main(){
    cin >> x >> k >> d;

    x = abs(x);
    long long cntmove = min(k, x/d);
    x -= cntmove * d;

    if(cntmove%2 == k%2){
        cout << x << endl;
    }else{
        cout << d - x << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
    int a, b;
    cin >> a >> b;

    for(int c = b; ;c--){
        if(b/c - (a-1)/c >= 2){
            cout << c << endl;
            return 0;
        }
    }

}
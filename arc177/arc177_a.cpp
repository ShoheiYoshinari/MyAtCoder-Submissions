#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int coin[6];
int n;
vector<int> x;

int main(){
    rep(i, 6) cin >> coin[i];
    cin >> n;
    vector<int> x(n);
    for(auto &p : x) cin >> p;

    rep(i, n){
        while(true){
            if(x[i] == 0) break;
            if(x[i] >= 500 && coin[5] > 0){
                coin[5]--;
                x[i] -= 500;
            }else if(x[i] >= 100 && coin[4] > 0){
                coin[4]--;
                x[i] -= 100;
            }else if(x[i] >= 50 && coin[3] > 0){
                coin[3]--;
                x[i] -= 50;
            }else if(x[i] >= 10 && coin[2] > 0){
                coin[2]--;
                x[i] -= 10;
            }else if(x[i] >= 5 && coin[1] > 0){
                coin[1]--;
                x[i] -= 5;
            }else if(x[i] >= 1 && coin[0] > 0){
                coin[0]--;
                x[i] -= 1;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int month, day;
int y, m, d;

int main(){
    cin >> month >> day;
    cin >> y >> m >> d;

    if(day == d){
        if(month == m){
            cout << y + 1 << " 1 1" << endl;

        }else{
            cout << y << ' ' << m + 1 << " 1" << endl;
        }
        
    }else{
        cout << y << ' ' << m << ' ' << d + 1 << endl;
    }
}
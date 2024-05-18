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

vector<ll> vec;

int main(){
    ll n;
    cin >> n;
    n--;
    if(n == 0) vec.push_back(n%5);
    while(n != 0){
        vec.push_back(n%5);
        n /= 5;
    }

    string str = "02468";
    for(int i = vec.size()-1; i >= 0; i--){
        rep(j, str.size()){
            if(vec[i] == j){
                cout << str[j];
            }
        }
    }
    cout << endl;
    return 0;
}
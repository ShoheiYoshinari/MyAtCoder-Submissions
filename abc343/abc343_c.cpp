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

long long n;
vector<long long> candidate;

int main(){
    cin >> n;

    long long pos;
    for(long long i = 1; i*i*i <= n; i++){
        long long num = i*i*i;
        candidate.push_back(num);
    }

    long long ans = 0;

    rep(i, candidate.size()){
        string s = to_string(candidate[i]);
        string t = s;
        reverse(t.begin(), t.end());
        if(s==t) ans = candidate[i];
    }
    cout << ans << endl;
    return 0;
}
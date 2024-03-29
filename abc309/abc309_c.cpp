#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> v;
    long long a, b;
    long long eaten = 0;
    rep(i, n){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        eaten += b;
    }
    sort(v.begin(), v.end());
    long long index = 0, day = 1;
    while(true){
        while(true){
            if(day - 1 == v[index].first){
                eaten -= v[index].second;
                index++;
            }else{
                break;
            }
        }
        if(eaten <= k){
            cout << day << endl;
            return 0;
        }else{
            day++;
        }
    }
}
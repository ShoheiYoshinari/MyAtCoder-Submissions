#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main(){
    int n, x, y;
    vector<pair<int, int> > town;
    cin >> n;
    rep(i, n){
        cin >> x >> y;
        town.emplace_back(x, y);
    }
    vector<int> pass;
    rep(i, n) pass.push_back(i);

    long double ssum = 0.0, cnt = 0;
    do{
        cnt++;
        long double sum = 0.0;
        rep2(i, 1, n) sum += sqrt((town[pass[i-1]].first - town[pass[i]].first) * (town[pass[i-1]].first - town[pass[i]].first)
                           + (town[pass[i-1]].second - town[pass[i]].second) * (town[pass[i-1]].second - town[pass[i]].second));
        ssum += sum;
    }while(next_permutation(all(pass)));

    cout << fixed << setprecision(10) << (long double) ssum / (long double) cnt << endl;
    return 0;
}
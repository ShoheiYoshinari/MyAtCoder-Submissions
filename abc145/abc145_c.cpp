#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

long double distance(ll x, ll y, ll nx, ll ny){
    return sqrt((x-nx)*(x-nx) + (y-ny)*(y-ny));
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pos;
    rep(i, n){
        ll x, y; cin >> x >> y;
        pos.push_back(make_pair(x, y));
    }
    
    vector<int> od(n);
    rep(i, n) od[i] = i;

    long double dist;
    long double sum = 0;
    ll cnt = 0;
    do{
        dist = 0;
        rep(i, n-1){
            dist += distance(pos[od[i]].first, pos[od[i]].second, pos[od[i+1]].first, pos[od[i+1]].second);
        }
        sum += dist;
        cnt++;
    }while(next_permutation(all(od)));
    cout << sum / (long double) cnt << endl;
    
}
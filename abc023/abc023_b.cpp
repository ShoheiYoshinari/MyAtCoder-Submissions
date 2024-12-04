#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    if(n%2 == 0){
        cout << "-1" << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = n/2, j = n/2; i >= 0, j < n; i--, j++){
        bool flag = true;
        //cout << s[i] << ' ' << s[j] << endl;
        if(cnt == 0){
            if(s[i] = 'b') cnt++;
            else flag = false;
        }else if(cnt%3 == 0){
            if(s[i] == 'b' && s[j] == 'b') cnt++;
            else flag = false;
        }else if(cnt%3 == 1){
            if(s[i] == 'a' && s[j] == 'c') cnt++;
            else flag = false;
        }else if(cnt%3 == 2){
            if(s[i] == 'c' && s[j] == 'a') cnt++;
            else flag = false;
        }

        if(!flag){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << --cnt << endl;
    return 0;
}
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

bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}


int n;
int main(){
    cin >> n;
    int s; int c;
    vector<tuple<int, int, int> > v(n);
    rep(i, n){
        cin >> s >> c;
        v.at(i) = make_tuple(s, c, i+1);
    }

    vector<int> remain;

    sort(v.rbegin(), v.rend());
    int p, q, r;
    tie(p, q, r) = v[0];
    remain.push_back(r);
    int fi = p;
    int se = q;
    rep2(i, 1, n){
        tie(p, q, r) = v[i];
        if(fi > p && se < q){
            continue;
        }else{
            remain.push_back(r);
            fi = p;
            se = q;
        }
    }
    sort(remain.begin(), remain.end());
    cout << remain.size() << endl;
    rep(i, remain.size()){
        cout << remain[i] << ' ';
    }
    cout << endl;
    return 0;

}
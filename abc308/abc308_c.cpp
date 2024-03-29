#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

bool desc_asc(pair<long double, int>& left, pair<long double, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
    int n;
    cin >> n;
    vector<long double> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<pair<long double, int>> win;
    rep(i, n){
        win.push_back({a[i]/(a[i] + b[i]), i+1});
    }
    sort(win.begin(), win.end(), desc_asc);

    rep(i, n){
        cout << win[i].second << ' ';
    }
    cout << endl;

}
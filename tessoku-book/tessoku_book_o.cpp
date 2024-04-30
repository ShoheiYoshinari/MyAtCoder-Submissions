#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int n;
int a[100009];
vector<int> st;
int ans[100009];

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
        st.push_back(a[i]);
    }

    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());

    rep(i, n){
        auto itr = lower_bound(st.begin(), st.end(), a[i]) - st.begin();
        cout << itr + 1 << ' ';
    }
    cout << endl;
    return 0;
}
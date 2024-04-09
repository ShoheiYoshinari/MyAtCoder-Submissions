#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n;
vector<int> st;

int main(){
    cin >> n;
    rep(i, 4){
        st.push_back(n%10);
        n /= 10;
    }
    bool ok1 = false, ok2 = false;

    reverse(st.begin(), st.end());

    if(st[0] == st[1] && st[1] == st[2] && st[2] == st[3]) ok1 = true;
    if((st[0] + 1)%10 == st[1] && (st[1] + 1)%10 == st[2] && (st[2] + 1)%10 == st[3]) ok2 = true;

    if(ok1 || ok2) cout << "Weak" << endl;
    else cout << "Strong" << endl;
    return 0;
}
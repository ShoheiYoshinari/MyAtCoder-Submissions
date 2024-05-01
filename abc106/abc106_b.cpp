#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    int ans = 0;
    do{
        int cnt = 0;

        rep(i, n){
            if(i%2 == 1 && n%i == 0) cnt++;
        }
        if(cnt == 8) ans++;
    }while(n--);
    cout << ans << endl;
    return 0;

}
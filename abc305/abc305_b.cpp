#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    char n[2];
    cin >> n[0] >> n[1];
    vector<int> dis{3,1,4,1,5,9};
    int ans = 0;

    int a;
    if(int(n[0]) > int(n[1])) {
        a = n[0];
        n[0] = n[1];
        n[1] = a;
    }
    for(int i = int(n[0] - 'A'); i < int(n[1] - 'A'); i++){
        ans += dis[i];
    }
    cout << ans << endl;

    
     
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n ,q;
    cin >> n >> q;
    int event = 0,p = 0;
    vector<int> player(101);

    for (int i = 1; i <= q; i++)
    {
        cin >> event >> p;
        if(event == 1){
            player[p]++;
        }else if(event == 2) {
            player[p] += 2;
        }else if(event == 3) {
            if(player[p] >= 2) {
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }     
    }
    cout << endl;
    return 0;
}
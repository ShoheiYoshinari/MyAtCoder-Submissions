#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int s;
    cin >> s;

    set<int> done;
    done.insert(s);
    

    rep2(i, 2, 1000000){
        if(s%2 == 0){
            s /= 2;
        }else{
            s = s * 3 + 1;
        }
        done.insert(s);
        if(done.size() != i){
            cout << i << endl;
            return 0;
        }
    }
}
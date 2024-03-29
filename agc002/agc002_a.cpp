#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a, b;
    cin >> a >> b;
    if(a < 0){
        if(b < 0){
            if((b - a - 1)%2 == 1){
                cout << "Negative" << endl;
            }else{
                cout << "Positive" << endl;
            }
        }else{
            cout << "Zero" << endl;
        }
    }else{
        cout << "Positive" << endl;
    }

}
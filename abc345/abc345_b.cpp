#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long long x;

int main(){
    cin >> x;
    if(x%10 == 0){
        cout << x/10 << endl;
    }else{
        if(x < 0){
            cout << x/10 << endl;
        }else{
            cout << x/10 + 1 << endl;
        }
    }
    return 0;

}
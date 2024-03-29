#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

bool isPrime(int x){
       int i;
       if(x < 2)return 0;
       else if(x == 2) return 1;
       if(x%2 == 0) return 0;
       for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
       return 1;
}

int main() {
    int x;
    cin >> x;

    rep2(i, x, 111111){
        if(isPrime(i)){
            cout << i << endl;
            return 0;
        }
    }
}
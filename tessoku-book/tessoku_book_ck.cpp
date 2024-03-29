#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int n;

bool ck(double x){
    double a = x*x*x + x;
    if(a > n) return true;
    else return false;
}

int main(){
    cin >> n;
    double left = 0, right = 100;
    rep(i, 20){
        double mid = (left + right)/2.0;
        bool ans = ck(mid);
        if(ans == true) right = mid;
        if(ans == false) left = mid;
    }
    cout << fixed << setprecision(5) << left << endl;
}
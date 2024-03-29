#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    string n;
    cin >> n;

    int sum = 0;

    for(int i = 0; i < n.size(); i++){
        if(n[i] == '1'){
            sum = sum*2 + 1;
        }else{
            sum = sum*2;
        }
    }
    cout << sum << endl;



}
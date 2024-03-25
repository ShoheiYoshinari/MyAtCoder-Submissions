#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

string s;

int main(){
    cin >> s;

    int maxaddsum = -1;

    rep(i, 1<<s.size()){
        int sum = 0;
        int addsum = 0;
        rep(j, s.size()){
            ll wari = (1 << j);
            if((i /wari) % 2 == 1){
                addsum++;
                sum += (int)(s[j] - '0');
            }
        }

        if(sum%3 == 0 && maxaddsum < addsum){
            maxaddsum = addsum;
        }
    }

    if(maxaddsum == 0){
        cout << "-1" << endl;
    }else{
        cout << s.size() - maxaddsum << endl;
    }
}
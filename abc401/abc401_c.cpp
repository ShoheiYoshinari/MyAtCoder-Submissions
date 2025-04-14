#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

int main() {
    
    long long n, k;
    cin >> n >> k;
    long long m = 0;

    vector<long long> cs(n+1, 0);

    rep(i, n+1){
        if(i < k){
            if(i == 0){
                m = 1;
                cs.at(i) = 1;
            }else{
                m = 1;
                cs.at(i) = abs(cs.at(i-1) + m); 
            }
            
        }else if (i == k){
            m = cs.at(i-1);
            cs.at(i) = abs(cs.at(i-1) + m);
        }else if(i > k){
			long long t = cs.at(i-1) - cs.at(i-(k+1));
			if(t < 0) m = t + 1000000000;
            else m = t;
            cs.at(i) = abs(cs.at(i-1) + m);
        }

        m %= 1000000000;
        cs.at(i) %= 1000000000;
        
    }

    long long ans = m % 1000000000;
    cout << ans << endl;

    return 0;
}
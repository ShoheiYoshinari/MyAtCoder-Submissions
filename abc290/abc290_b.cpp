#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    int i = 0;

    while (k > cnt)
    {
        if(s[i] == 'o')
            cnt++;
            i++;   
    }
    for (int j = i; j < n; j++)
    {
        s[j] = 'x';
    }
    
    cout << s << endl;
    

}
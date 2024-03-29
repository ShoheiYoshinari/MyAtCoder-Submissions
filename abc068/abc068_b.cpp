#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int max = -1;
    int ans = -1;
    for (int i = 1; i < n + 1 ; i++)
    {
        int count = 0;
        int x = i;
        while (x % 2 == 0)
        {
            x /= 2;
            count++;
        }
        if(max < count) 
        {
            max = count;
            ans = i;
        }
        
    }
    cout << ans << endl;
}


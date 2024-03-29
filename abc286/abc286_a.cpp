#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,P,Q,R,S;
    cin >> N >> P >> Q >> R >> S;

    vector<int> ans(N);

    for (int i = 0; i < N; i++)
    {
        cin >> ans.at(i);
    }
    

    for (int i = P - 1; i < Q; i++)
    {
        swap(ans.at(i), ans.at(R + i - P));
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans.at(i) << " ";
    }
    
    cout << endl;
}
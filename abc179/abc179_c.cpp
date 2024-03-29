#include <iostream>
using namespace std;
int main(void){
    int n;
    long long ans = 0;
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        ans += (n-1)/i;
    }
    cout << ans << endl;
}
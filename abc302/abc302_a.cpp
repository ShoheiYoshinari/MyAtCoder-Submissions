#include <iostream>
using namespace std;
int main(void){
    long long a, b;
    cin >> a >> b;
    if(a%b == 0) cout << a/b << endl;
    else cout << a/b + 1 << endl;
    
}

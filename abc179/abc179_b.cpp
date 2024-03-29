#include <iostream>
using namespace std;
int main(void){
    int n, cnt = 0;
    int d1, d2;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> d1 >> d2;
        if(d1 == d2) cnt++;
        else cnt = 0;

        if(cnt >= 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
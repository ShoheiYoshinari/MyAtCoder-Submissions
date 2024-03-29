#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    if(s[s.size()-1] == 's') s += "es";
    else s += "s";

    cout << s << endl;
}
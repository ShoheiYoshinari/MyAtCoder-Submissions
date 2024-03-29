#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int a_place = 0; 
    int z_place = 0;
    bool first = false;
    for (int i = 0; i < s.size(); i++)
    {
        if(first == false){
            if(s[i] == 'A') {
                a_place = i;
                first = true;
            }
        }
        if(s[i] == 'Z') z_place = i;
    }
    cout << z_place - a_place + 1 << endl;
}
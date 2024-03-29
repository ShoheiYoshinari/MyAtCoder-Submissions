#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    vector<int> y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<int> dist(n, -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);
    
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        rep(i, n){
            if(dist[i] == -1){
                double di = sqrt((x[i] - x[v])*(x[i] - x[v]) + (y[i] - y[v])*(y[i] - y[v]));
                if((double)d >= di){
                    dist[i] = 0;
                    que.push(i);
                }
            }
        }
    }
    rep(i, n){
        if(dist[i] == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
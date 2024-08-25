#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
bool must_include[MAXN];
int n, k;
int result = 0;

bool dfs(int node, int parent) {
    bool include = must_include[node]; 
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            if (dfs(neighbor, node)) {
                include = true;
                result++;
            }
        }
    }
    return include;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int v;
    for (int i = 0; i < k; ++i) {
        cin >> v;
        must_include[v] = true;
    }

    dfs(v, -1);
    cout << result + 1 << endl;

    return 0;
}

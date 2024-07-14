#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    long long weight;
};

void dijkstra(int start, const vector<long long>& node_weights, const vector<vector<Edge>>& graph, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({node_weights[start], start});
    dist[start] = node_weights[start];
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            long long weight = edge.weight;
            if (dist[u] + weight + node_weights[v] < dist[v]) {
                dist[v] = dist[u] + weight + node_weights[v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<long long> node_weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> node_weights[i];
    }
    
    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        --U; // adjust to 0-based index
        --V; // adjust to 0-based index
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }
    
    vector<long long> dist(N, INF);
    dijkstra(0, node_weights, graph, dist);
    
    // 各頂点への最小の重みを出力
    for (int i = 1; i < N; ++i) {
        if (dist[i] == INF) {
            cout << "INF" << ' ';
        } else {
            cout << dist[i] << ' ';
        }
    }
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void tarjanDFS(int node, vector<vector<int>>& graph, vector<int>& ids, vector<int>& lowLink, vector<bool>& onStack, stack<int>& nodeStack, int& id, vector<vector<int>>& cycles) {
    ids[node] = lowLink[node] = id++;
    nodeStack.push(node);
    onStack[node] = true;

    for (int neighbor : graph[node]) {
        if (ids[neighbor] == -1) {
            tarjanDFS(neighbor, graph, ids, lowLink, onStack, nodeStack, id, cycles);
            lowLink[node] = min(lowLink[node], lowLink[neighbor]);
        }
        else if (onStack[neighbor]) {
            lowLink[node] = min(lowLink[node], ids[neighbor]);
        }
    }

    if (ids[node] == lowLink[node]) {
        vector<int> cycle;
        int topNode;
        do {
            topNode = nodeStack.top();
            nodeStack.pop();
            onStack[topNode] = false;
            cycle.push_back(topNode);
        } while (topNode != node);
        cycles.push_back(cycle);
    }
}

vector<vector<int>> findCycles(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> ids(n, -1);
    vector<int> lowLink(n, -1);
    vector<bool> onStack(n, false);
    stack<int> nodeStack;
    int id = 0;
    vector<vector<int>> cycles;

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            tarjanDFS(i, graph, ids, lowLink, onStack, nodeStack, id, cycles);
        }
    }

    return cycles;
}


void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    a--,b--;
    vector<vector<int>> graph(n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        u-- , v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // cout << a << ' ' << b << endl;
    vector<vector<int>> cycles = findCycles(graph);

    // In ra các chu trình
    for (const auto& cycle : cycles) {
        cout << "Cycle: ";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }

}
int main() {
      if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
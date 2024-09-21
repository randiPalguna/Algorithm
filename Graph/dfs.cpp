#include <bits/stdc++.h>

using namespace std;

struct graph {
  int nodeCount;
  vector<vector<pair<int, int>>> edges; // adjacency list

  void init(int nodeCnt) {
    nodeCount = nodeCnt;
    for (int i = 0; i <= nodeCount; i++) {  // Adding additional 1 node in case of 1-indexed input
      edges.push_back({});
    }
  }

  void addEdge(int src, int dst, int weight, bool undirected) {
    edges[src].push_back({dst, weight});
    if (undirected) {
      edges[dst].push_back({src, weight});
    }
  }
  
  void dfs(int start, int goal) {
    stack<int> nodes;
    vector<bool> visited(nodeCount);
    vector<int> pred(nodeCount, -1);
    
    nodes.push(start);
    visited[start] = 1;
    
    while (!nodes.empty()) {
      int currNode = nodes.top();
      int nextNode;
      nodes.pop();

      for (auto it : edges[currNode]) {
        nextNode = it.first;
        if (!visited[nextNode]) {
          nodes.push(nextNode);
          visited[nextNode] = 1;  // To push this node only once in the stack
          pred[nextNode] = currNode;

          if (nextNode == goal) {
            while (!nodes.empty()) {
              nodes.pop();
            }
            break;
          }
        }
      }
    }
    // Print the path from start to goal
    int i = goal;
    cout << goal << " <- ";
    while (pred[i] != -1) {
      cout << pred[i];
      i = pred[i];
      cout << ((pred[i] == -1) ? "" : " <- ");
    }
    cout << '\n';
  }
};

int main() {
  graph g;
  int N, E;
  cin >> N >> E;
  g.init(N);
  for (int i = 0; i < E; i++) {
    int src, dst;
    cin >> src >> dst;
    g.addEdge(src, dst, 0, 0);
  }
  g.dfs(0, 4);
  return 0;
}

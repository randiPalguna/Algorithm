#include <bits/stdc++.h>

using namespace std;

struct graph {
  int nodeCount;
  vector<vector<pair<int, int>>> edges; // Adjacency list

  void init(int nodeCnt) {
    nodeCount = nodeCnt;
    for (int i = 0; i < nodeCount; i++) {
      edges.push_back({});
    }
  }

  void addEdge(int src, int dst, int weight, bool undirected) {
    edges[src].push_back({dst, weight});
    if (undirected) {
      edges[dst].push_back({src, weight});
    }
  }
    
  void bfs(int start, int goal) {
    vector<int> nodes;
    vector<bool> visited(nodeCount);
    vector<int> pred(nodeCount, -1);
    
    nodes.push_back(start);
    visited[start] = 1;

    while (!nodes.empty()) {
      int currNode = nodes.front();
      int nextNode;
      nodes.erase(nodes.begin());

      for (auto it : edges[currNode]) {
        nextNode = it.first;
        if (!visited[nextNode]) {
          nodes.push_back(nextNode); // To push_back this node only once in the vector
          visited[nextNode] = 1;
          pred[nextNode] = currNode;
        }

        if (nextNode == goal) {
          nodes.clear();
          break;
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
  g.bfs(0, 4);
  return 0;
}

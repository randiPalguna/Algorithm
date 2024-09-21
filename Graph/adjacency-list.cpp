#include <bits/stdc++.h>

using namespace std;

// unweighted graph
struct graph {
  vector<vector<int>> edges;

  void init(int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
      edges.push_back({});
    }
  }

  void addEdge(int src, int dst, bool undirected) {
    edges[src].push_back(dst);
    if (undirected) {
      edges[dst].push_back(src);
    }
  }

  void check() {
    for (int i = 0; i < (int) edges.size(); i++) {
      cout << i << "| ";
      for (int j = 0; j < (int) edges[i].size(); j++) {
        cout << edges[i][j] << " ";
      }
      cout << '\n';
    }
  }
};

// Weighted graph
struct graphW {
  vector<vector<pair<int, int>>> edges;

  void init(int nodeCount) {
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
  
  void check() {
    for (int i = 0; i < (int) edges.size(); i++) {
      cout << i << "| ";
      for (int j = 0; j < (int) edges[i].size(); j++) {
        cout << "(" << edges[i][j].first << " = " << edges[i][j].second << ") ";
      }
      cout << '\n';
    }
  }
};

int main() {
  graphW g;
  g.init(5);
  g.addEdge(0, 1, 5, 0);
  g.addEdge(1, 4, 53, 0);
  g.addEdge(2, 1, 23, 0);
  g.addEdge(3, 4, 141, 0);
  g.check();
  return 0;
}

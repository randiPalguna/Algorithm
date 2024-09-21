#include <bits/stdc++.h>

using namespace std;

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

  void delEdge(int src, int dst, bool undirected) {
    for (auto it = edges[src].begin(); it != edges[src].end(); it++) {
      if (*it == dst) {
        edges[src].erase(it);
        break;
      }
    }
    if (undirected) {
      for (auto it = edges[dst].begin(); it != edges[dst].end(); it++) {
        if (*it == src) {
          edges[dst].erase(it);
          break;
        }
      }
    }
  }

  void printList() {
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
  
  void delEdge(int src, int dst, bool undirected) {
    for (auto it = edges[src].begin(); it != edges[src].end(); it++) {
      if (it->first == dst) {
        edges[src].erase(it);
        break;
      }
    }
    if (undirected) {
      for (auto it = edges[dst].begin(); it != edges[dst].end(); it++) {
        if (it->first == src) {
          edges[dst].erase(it);
          break;
        }
      }
    }
  }

  void printList() {
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
  graph g;
  g.init(5);
  g.addEdge(0, 1, 0);
  g.addEdge(1, 4, 0);
  g.addEdge(2, 1, 0);
  g.addEdge(3, 4, 0);
  g.delEdge(3, 4, 0);
  g.delEdge(0, 1, 0);
  g.printList();
  return 0;
}

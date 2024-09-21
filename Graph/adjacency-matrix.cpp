#include <bits/stdc++.h>

using namespace std;

struct graph {
  vector<vector<int>> edges;
  
  void init(int nodeCount) {
    vector<int> temp(nodeCount, 0);
    for (int i = 0; i < nodeCount; i++) {
      edges.push_back(temp);
    }
  }

  void check() {
    cout << edges.size() << '\n';
    for (int i = 0; i < (int)edges.size(); i++) {
      for (int j = 0; j < (int)edges.size(); j++) {
        cout << edges[i][j] << " ";
      }
      cout << '\n';
    }
  }
  
  // If unweighted graph
  void addEdge(int src, int dst, bool undirected) {
    edges[src][dst] = 1;
    if (undirected) {
      edges[dst][src] = 1;
    }
  }

  // If weighted graph
  void addEdgeW(int src, int dst, int weigth, bool undirected) {
    edges[src][dst] = weigth;
    if (undirected) {
      edges[dst][src] = weigth;
    }
  }
};

int main() {
  graph g;
  g.init(5);
  g.check();
  g.addEdgeW(1, 4, 10, 1);
  g.addEdgeW(1, 2, 69, 1);
  g.addEdgeW(2, 3, 25, 1);
  g.check();
  return 0;
}

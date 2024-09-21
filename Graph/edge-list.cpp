#include <bits/stdc++.h>

using namespace std;

// Unweighted graph
struct graph {
  vector<pair<int, int>> edges; // No need for initialization space

  void addEdge(int src, int dst, bool undirected) {
    edges.push_back({src, dst});
    if (undirected) {
      edges.push_back({dst, src});
    }
  }

  void delEdge(int src, int dst, bool undirected) {
    for (auto it = edges.begin(); it != edges.end(); it++) {
      if ((*it).first == src && (*it).second == dst) {
        edges.erase(it);
        break;
      }
    }
    if (undirected) {
      for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->first == dst && it->second == src) {
          edges.erase(it);
          break;
        }
      }
    }
  }

  void printList() {
    for (int i = 0; i < (int) edges.size(); i++) {
      cout << edges[i].first << " " << edges[i].second << '\n';
    }
  }
};

// Weighted graph
struct graphW {
  vector<pair<pair<int, int>, int>> edges; // No need for initialization space

  void addEdge(int src, int dst, int weight, bool undirected) {
    edges.push_back({{src, dst}, weight});
    if (undirected) {
      edges.push_back({{dst, src}, weight});
    }
  }

  void delEdge(int src, int dst, bool undirected) {
    for (auto it = edges.begin(); it != edges.end(); it++) {
      if (it->first.first == src && it->first.second == dst) {
        edges.erase(it);
        break;
      }
    }
    if (undirected) {
      for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->first.first == dst && it->first.second == src) {
          edges.erase(it);
          break;
        }
      }
    }
  }

  void printList() {
    for (int i = 0; i < (int) edges.size(); i++) {
      cout << edges[i].first.first << " " << edges[i].first.second << " = " << edges[i].second << '\n';
    }
  }
};

int main() {
  graphW g;
  g.addEdge(0, 2, 5, 0);
  g.addEdge(0, 3, 11, 0);
  g.addEdge(5, 9, 7, 0);
  g.delEdge(5, 9, 0);
  g.delEdge(0, 3, 0);
  g.printList();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct graph { // zero-indexed adjacent matrix
  int V, E;
  vector<vector<pair<int, int>>> adj;

  void init(int vertexCount) {
    V = vertexCount;
    for (int i = 0; i < V; i++) {
      adj.push_back({});
    }
  }

  void addEdge(int v1, int v2, int weight) {  // tsp problem for undirected graph
    adj[v1].push_back({v2, weight});
    adj[v2].push_back({v1, weight});
  }

  void prints() {
    for (int i = 0; i < V; i++) {
      cout << i << " | ";
      for (auto it : adj[i]) {
        cout << "(" << it.first << " " << it.second << ") ";
      }
      cout << '\n';
    }
  }
  
  void generate_state(vector<int> &indv) {
    srand(time(0));
    while ((int) indv.size() < V) {
      int random = rand() % V;
      if (find(indv.begin(), indv.end(), random) == indv.end()) {
        indv.push_back(random);
      }
    }
  }

  int fitness(vector<int> path) {
    int fitness = 0;
    for (int i = 0; i < V - 1; i++) {
      int current = path[i];
      int next = path[i + 1];
      for (auto it : adj[current]) {
        if (it.first == next) {
          fitness += it.second;
          break;
        }
      }
    }
    // add the last node because it is a cycled path
    for (auto it : adj[path[V - 1]]) {
      if (it.first == path[0]) {
        fitness += it.second;
      }
    }
    return fitness;
  }

  void hill_climbing() {
    vector<int> state;
    generate_state(state);

    bool local_optima = false;
    while (!local_optima) {
      local_optima = true;
      int currentBest = fitness(state);
      vector<int> neighbor;

      for (int i = 0; i < V - 1; i++) {
        for (int j = i + 1; j < V; j++) {
          neighbor = state;
          swap(neighbor[i], neighbor[j]);
          int neighborFit = fitness(neighbor);

          if (neighborFit < currentBest) {
            local_optima = false;
            currentBest = neighborFit;
            state = neighbor;
          }
        }
      }
    }
    
    cout << "Answer : ";
    for (int i = 0; i < V; i++) {
      cout << state[i] << " ";
    }
    cout << state[0] << '\n';
    cout << "Best fitness found: " << fitness(state);
  }
};

int main() {
  graph g;
  int n;
  cin >> n; // vertex count
  g.init(n);
  for (int i = 0; i < ((n * (n - 1)) / 2); i++) {
    int a, b, w;
    cin >> a >> b >> w; // v1 v2 weight
    g.addEdge(a, b, w);
  }

  g.hill_climbing();
  return 0;
}

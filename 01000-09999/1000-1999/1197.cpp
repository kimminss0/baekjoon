/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2024-09-15
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parents; // parent's id if non-root; negated rank if root.

public:
  UnionFind(int num_vertices) : parents(num_vertices + 1, 0) {}

  // path halving
  int find(int vertex) {
    // assert vertex > 0
    while (parents[vertex] > 0) {
      if (parents[parents[vertex]] > 0) {
        parents[vertex] = parents[parents[vertex]];
        vertex = parents[vertex];
      } else {
        return parents[vertex];
      }
    }
    return vertex;
  }

  // union
  void unite(int vertex1, int vertex2) {
    int root1 = find(vertex1);
    int root2 = find(vertex2);
    int rank1 = -parents[root1];
    int rank2 = -parents[root2];

    if (rank1 > rank2) {
      parents[root2] = root1;
    } else {
      parents[root1] = root2;
      if (rank1 == rank2) {
        parents[root2]--;
      }
    }
  }
};

struct Edge {
  int vertex1;
  int vertex2;
  int weight;
  bool operator<(const Edge &that) const { return this->weight < that.weight; }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  UnionFind uf{num_vertices};
  vector<Edge> edges;
  edges.reserve(num_edges);

  for (int i = 0; i < num_edges; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    edges.emplace_back(Edge{v, u, w});
  }
  sort(edges.begin(), edges.end());

  int mst_weight = 0;
  for (const auto &[u, v, weight] : edges) {
    if (uf.find(u) != uf.find(v)) {
      uf.unite(u, v);
      mst_weight += weight;
    }
  }
  cout << mst_weight;
  return 0;
}


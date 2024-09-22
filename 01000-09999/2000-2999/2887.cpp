/**
 * @brief BOJ No. 2887 "행성 터널"
 *
 * @author Minseo Kim <kimminss0@outlook.kr>
 * @details 밀집 그래프로 보고 Prim으로 풀면 시간 및 메모리 제한에 걸린다.
 * 이 문제에서 대부분의 간선들은 MST 알고리즘 실행 전에 미리 제거될 수 있는데,
 * |E| = |V|^2에서 |E| = 3|V|까지 줄일 수 있어 사실상 희소 그래프로 풀 수 있기에
 * Kruskal로 구현한다.
 */

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parent;

public:
  UnionFind(int N) : parent(N) {
    for (int i = 0; i < N; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    // path compression
    return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return false;
    }
    parent[rootX] = rootY;
    return true;
  }
};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int N;
  cin >> N;

  // idx, coordinate (along the axis)
  vector<pair<int, int>> x(N), y(N), z(N);

  for (int i = 0; i < N; i++) {
    x[i].first = i;
    y[i].first = i;
    z[i].first = i;
    cin >> x[i].second >> y[i].second >> z[i].second;
  }

  if (N == 1) {
    cout << 0;
    return 0;
  }

  // sort by coordinate
  auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second < b.second;
  };
  sort(x.begin(), x.end(), cmp);
  sort(y.begin(), y.end(), cmp);
  sort(z.begin(), z.end(), cmp);

  // w, v, u
  vector<tuple<int, int, int>> edges;
  edges.reserve(N * 3);
  for (const auto &ax : {x, y, z}) {
    for (int it1 = 0, it2 = 1; it2 < N; it1++, it2++) {
      int v = ax[it1].first;
      int u = ax[it2].first;
      int w = abs(ax[it1].second - ax[it2].second);
      edges.emplace_back(make_tuple(w, v, u));
    }
  }
  // sort by weight, ascending
  std::sort(edges.begin(), edges.end(),
            [](auto a, auto b) -> bool { return get<0>(a) < get<0>(b); });

  // KruskalMST
  UnionFind uf(N);
  int mstWeight = 0;
  for (auto [w, v, u] : edges) {
    if (uf.unite(v, u)) {
      mstWeight += w;
    }
  }
  cout << mstWeight;

  return 0;
}


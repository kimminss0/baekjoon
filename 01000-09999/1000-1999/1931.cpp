/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-11-09
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  vector<pair<int, int>> vec(N);
  for (auto &v : vec) {
    cin >> v.second >> v.first;
  }
  sort(vec.begin(), vec.end());
  int cnt = 0, t = 0;
  for (auto &v : vec) {
    if (v.second >= t) {
      t = v.first;
      ++cnt;
    }
  }
  cout << cnt;
}

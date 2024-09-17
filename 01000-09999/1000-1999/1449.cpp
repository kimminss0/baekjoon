/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-11-09
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int N, L;
  cin >> N >> L;
  vector<int> vec(N);
  for (auto &v:vec) {
    cin >> v;
  }
  sort(vec.begin(), vec.end());
  int cnt = 0;
  int p = 0;
  for (auto v:vec) {
    if (v <= p) {
      continue;
    }
    p = v + L - 1;
    ++cnt;
  }
  cout << cnt;
}

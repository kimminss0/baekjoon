/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-11-15
 */
#include <iostream>
#include <vector>
using namespace std;

int bs(int *res, const int t, const int len) {
  int lo{0}, hi{len}, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (res[mid] >= t) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return hi;
}

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, v, l{1};
  int res[1000000];
  cin >> N >> res[0];
  for (int i = 1; i < N; ++i) {
    cin >> v;
    if (v > res[l-1]) {
      res[l++] = v;
    } else {
      res[bs(res, v, l)] = v;
    }
  }
  cout << l;
}

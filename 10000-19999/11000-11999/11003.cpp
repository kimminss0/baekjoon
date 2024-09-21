/**
 * @brief BOJ No. 11003 "최솟값 찾기"
 *
 * @author Minseo Kim <kimminss0@outlook.kr>
 * @details Priority queue를 떠올리기 쉬운 문제다. 그렇게 풀다보면 back에서
 * pop을 하고 싶다는 생각이 들 수 있다. 더 생각해보면, 이 문제는 애초에 deque로
 * 풀 수 있는 문제임을 알아차릴 수 있다.
 */

#include <deque>
#include <iostream>
#include <utility>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  deque<pair<int, int>> dq; // idx, value

  int N, L;
  cin >> N >> L;

  for (int idx = 0; idx < N; idx++) {
    int val;
    cin >> val;
    while (!dq.empty() && val <= dq.back().second) {
      dq.pop_back();
    }
    dq.emplace_back(make_pair(idx, val));
    if (dq.front().first <= idx - L) {
      dq.pop_front();
    }
    cout << dq.front().second << " ";
  }
  return 0;
}

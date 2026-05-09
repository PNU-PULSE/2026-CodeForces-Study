#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  int ans = (n == 1) ? 1 : 2;
  while (n--) cout << ans << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}

// 최솟값 또는 최댓값을 삭제하기 때문에 모든 경우에 나를 지우지 않는게 가능하다.
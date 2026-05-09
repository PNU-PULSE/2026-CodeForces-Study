#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;

  if (x + y == 1 && x == 1) {
    cout << "NO\n";
    return;
  } else if (x + y == 2 && (x == 2 || y == 2)) {
    cout << "NO\n";
    return;
  }
  if (x > y) {
    cout << "NO\n";
    return;
  }

  vector<pair<int, int>> v;
  if ((x + y) & 1) {
    for (int i = 1; i <= 2 * x; i++) v.push_back({i, i + 1});
    for (int i = 2 * x + 2; i <= x + y; i++) v.push_back({1, i});

  } else {
    if (x == 0) {
      cout << "NO\n";
      return;
    }
    for (int i = 1; i <= 2 * (x - 1); i++) v.push_back({i, i + 1});
    for (int i = 2 * (x - 1) + 2; i <= x + y; i++) v.push_back({1, i});
  }
  cout << "YES\n";
  for (auto [i, j] : v) cout << i << ' ' << j << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
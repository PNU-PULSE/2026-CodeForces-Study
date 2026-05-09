#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int t;
  cin >> t;
  return t;
}

int solve() {
  int n;
  cin >> n;

  for (int i = 0; i < 3; i++) {
    int t[] = {1, 2, 3, 1};
    int res = query(t[i], t[i + 1]);
    if (res == 1) return t[i];
  }
  for (int i = 4; i <= 2 * n - 2 / 2; i += 2) {
    int res = query(i, i + 1);
    if (res == 1) return i;
  }
  return 2 * n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int res = solve();
    cout << "! " << res << endl;
  }
}
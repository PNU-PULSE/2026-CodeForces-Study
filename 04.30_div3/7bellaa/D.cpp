#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, mid, l, r, ans = 1;
  bitset<100001> vis;
  cin >> n;
  vector<int> v(2 * n);
  vector<vector<int>> idx(n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> v[i];
    idx[v[i]].push_back(i);
  }

  mid = idx[0][0], vis = 1;
  for (int i = 0; mid - i >= 0 && mid + i < 2 * n; i++) {
    if (v[mid - i] != v[mid + i]) break;
    vis[v[mid - i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = max(ans, i);
      break;
    }
  }

  mid = idx[0][1], vis = 1;
  for (int i = 0; mid - i >= 0 && mid + i < 2 * n; i++) {
    if (v[mid - i] != v[mid + i]) break;
    vis[v[mid - i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = max(ans, i);
      break;
    }
  }

  l = idx[0][0], r = idx[0][1], vis = 1;
  bool flag = true;
  while (l <= r) {
    if (v[l] != v[r]) {
      flag = false;
      break;
    }
    vis[v[l]] = 1;
    l++;
    r--;
  }
  if (!flag) {
    cout << ans << '\n';
    return;
  }

  l = idx[0][0], r = idx[0][1];
  while (l >= 0 && r < 2 * n) {
    if (v[l] != v[r]) break;
    vis[v[l]] = 1;
    l--;
    r++;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = max(ans, i);
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
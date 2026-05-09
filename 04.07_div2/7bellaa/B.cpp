#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 200001;

void solve() {
  int n, k, p;
  cin >> n >> k;
  vector<char> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> p;
  p--;

  int l = 0, r = n - 1, cnt = 0;
  bool flag = true;
  while (l < p || p < r) {
    if (l < p && p < r) {
      if ((flag && a[l] == a[p]) || (!flag && a[l] != a[p])) {
        l++;
        continue;
      }
      if ((flag && a[r] == a[p]) || (!flag && a[r] != a[p])) {
        r--;
        continue;
      }

      flag = !flag;
      cnt++;
      if ((flag && a[l] != a[p] && a[r] != a[p]) ||
          (!flag && a[l] == a[p] && a[r] == a[p])) {
        l++;
        r--;
      } else if ((flag && a[l] != a[p]) || (!flag && a[l] == a[p])) {
        l++;
      } else {
        r--;
      }
    } else if (l < p) {
      if ((flag && a[l] != a[p]) || (!flag && a[l] == a[p])) {
        cnt++;
        flag = !flag;
      }
      l++;
    } else if (p < r) {
      if ((flag && a[r] != a[p]) || (!flag && a[r] == a[p])) {
        cnt++;
        flag = !flag;
      }
      r--;
    }
    // cout << l << ' ' << r << ' ' << cnt << '\n';
  }
  if (cnt & 1) cnt++;
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
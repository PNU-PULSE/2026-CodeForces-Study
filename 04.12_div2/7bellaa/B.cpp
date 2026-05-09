#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long t, h, u;
  cin >> t >> h >> u;
  long long mn = min(t, u), ans = 0;
  ans += mn * 4LL;
  t -= mn;
  u -= mn;
  if (t == 0) {
    ans += (h + u) * 3LL;
    cout << ans << '\n';
    return;
  }

  mn = min(t / 2, h);
  ans += 7LL * mn;
  t -= 2LL * mn;
  h -= mn;

  mn = min(t, h);
  ans += 5LL * mn;
  t -= mn;
  h -= mn;

  if (t == 0) {
    ans += 3LL * h;
  } else {
    ans += 3LL * t;
    ans -= (t - 1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
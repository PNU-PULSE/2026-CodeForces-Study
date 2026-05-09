#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  auto failure = [](string_view sv) -> vector<int> {
    vector<int> f(sv.size());
    for (int i = 1, j = 0; i < (int)sv.size(); i++) {
      while (j > 0 && sv[i] != sv[j]) j = f[j - 1];
      if (sv[i] == sv[j]) f[i] = ++j;
    }
    return f;
  };

  auto query = [&](int l, int r) -> ll {
    string_view sv(s.begin() + l - 1, s.begin() + r);
    vector<ll> dp(sv.size());
    auto F = failure(sv);
    ll res = dp[0] = 1;

    for (int i = 1; i < (int)sv.size(); i++) {
      dp[i] = 1;
      int t = i + 1 - F[i];
      int q = (i + 1) / t, r = (i + 1) % t;

      dp[i] = dp[t - 1] * q;
      if (r) dp[i] += dp[r - 1];
      res += dp[i];
    }
    return res;
  };

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
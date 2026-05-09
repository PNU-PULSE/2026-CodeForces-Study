#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, cnt = 0;
  string s;
  cin >> n >> s;

  for (char c : s) {
    if (c == ')')
      cnt--;
    else
      cnt++;
  }
  if (cnt)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
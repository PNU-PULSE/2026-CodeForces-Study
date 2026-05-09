#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;

  int bal = 0, diff = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '(' && b[i] == '(')
      ++bal;
    else if (a[i] == ')' && b[i] == ')')
      --bal;
    else
      diff ^= 2;

    if ((diff == 0 && bal < 0) || (diff == 2 && bal - 1 < 0)) {
      cout << "NO\n";
      return;
    }
  }
  if (bal)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
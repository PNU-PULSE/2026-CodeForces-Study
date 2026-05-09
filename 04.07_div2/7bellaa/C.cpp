#include <bits/stdc++.h>
using namespace std;

bool check(int n, int a) {
  if (n == 1 || a == 1) return true;
  if (gcd(n, a) == 1) return true;
  return false;
}

void solve() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  if (check(n, a) && check(m, b) && gcd(n, m) <= 2)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool isprime[200001];

void solve() {
  int x, y;
  cin >> x >> y;
  int gap = abs(x - y);

  int cnt = 0;
  for (int i = 1; i <= gap; i++) {
    if (gap % i == 0) cnt++;
  }
  if (gap == 0) cnt = 1;
  cout << cnt << '\n';
  while (x--) cout << "1 ";
  while (y--) cout << "-1 ";
  if (cnt) cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
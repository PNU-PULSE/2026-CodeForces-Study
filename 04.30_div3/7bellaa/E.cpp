#include <bits/stdc++.h>
using namespace std;

// 내 왼쪽에 나보다 높이가 크거나 같은 블록이 연속으로 몇개 있는지?
void solve() {
  int n;
  cin >> n;
  vector<int> v(n), cnt(n);
  for (int& i : v) cin >> i;

  stack<int> S;
  for (int i = n - 1; i >= 0; i--) {
    while (!S.empty() && v[S.top()] > v[i]) {
      cnt[S.top()] = S.top() - i - 1;
      S.pop();
    }
    S.push(i);
  }
  while (!S.empty()) {
    cnt[S.top()] = S.top();
    S.pop();
  }

  int minh = v[n - 1];
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    minh = min(minh, v[i]);
    ans += v[i] - minh;
  }
  cout << ans + *max_element(cnt.begin(), cnt.end()) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
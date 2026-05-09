#include <bits/stdc++.h>
using namespace std;

string solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];

  for (int i = 0; i < n - k; i++) {
    int j = n - 1 - i;
    if (B[i] == -1) B[i] = A[i];
    if (B[j] == -1) B[j] = A[j];
    if (A[i] != B[i] || A[j] != B[j]) return "NO";
  }

  vector<int> cnt(n + 1);
  int wildcard = 0;
  for (int i = n - k; i < k; i++) {
    cnt[A[i]]++;
    (B[i] == -1) ? wildcard++ : cnt[B[i]]--;
  }
  if (*min_element(cnt.begin(), cnt.end()) < 0 ||
      accumulate(cnt.begin(), cnt.end(), 0) > wildcard)
    return "NO";

  return "YES";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) cout << solve() << '\n';
}
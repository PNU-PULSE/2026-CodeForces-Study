#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_VALUE = 200'000;
const int MOD = 676'767'677;
vector<int> isPrime(2000001, true);
vector<int> primes;
void solve() {
  int x, y; cin >> x >> y;
  ll n = abs(x - y);

  if (x == y || n == 1) {
    cout << "1\n";
    for (int i=0 ; i<x ; i++) cout << "1 ";
    for (int i=0 ; i<y ; i++) cout << "-1 ";
    cout << "\n";
    return;
  }

  ll cnt = 1;
  
  for (auto p : primes) {
    if (n % p == 0) {
      ll x = 1;
      while (n != 0 && n % p == 0) {
        ++x;
        n /= p;
      }  
      cnt *= x;
      cnt %= MOD;
      if (n == 0) break;
    }
  }

  cout << cnt << "\n";
  for (int i=0 ; i<x ; i++) cout << "1 ";
  for (int i=0 ; i<y ; i++) cout << "-1 ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  isPrime[0] = isPrime[1] = false;
  for (int i=2 ; i<=MAX_VALUE ; i++) {
    for (int j=i+i ; j<=MAX_VALUE ; j+=i) {
      isPrime[j] = false;
    }
  }
  for (int i=2 ; i<=MAX_VALUE ; i++) {
    if (isPrime[i]) primes.push_back(i);
  }

  int t; cin >> t;
  while (t--) {
    solve();
  }
}

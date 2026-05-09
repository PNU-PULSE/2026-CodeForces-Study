#include <bits/stdc++.h>
using namespace std;

const int P_MAX = 200000;
vector<long long> primes;
bool isprime[P_MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(&isprime[2], &isprime[P_MAX], true);
  for (int i = 2; i < P_MAX; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (int j = i << 1; j < P_MAX; j += i) isprime[j] = false;
    }
  }

  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << "1 2 ";
    for (int i = 0; i < n - 2; i++) cout << primes[i] * primes[i + 1] << ' ';
    cout << '\n';
  }
}

// prime을 int로 해서 두개 곱할때 오버플로우 나서 틀림
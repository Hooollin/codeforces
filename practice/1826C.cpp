#include <iostream>
#include <set>
#include <vector>

using namespace std;

constexpr int MAXN = 10000000;

set<int> PRIMES;

bool is_strongly_composite(int x, vector<int> *primes,
                           vector<int> *composites) {
  if (x == 1) {
    return false;
  }
  if (PRIMES.find(x) != PRIMES.end()) {
    return false;
  }
  int a = 0, b = 0;
  for (int i = 2; i <= x; i++) {
    if (x % i == 0) {
      if (PRIMES.find(i) != PRIMES.end()) {
        a += 1;
        if (primes != nullptr)
          primes->push_back(i);
      } else {
        b += 1;
        if (composites != nullptr)
          composites->push_back(i);
      }
    }
  }
  return a <= b;
}

void init() {
  for (long long k = 2; k <= 10000; k++) {
    bool good = true;
    for (int i = 2; (long long)i * i <= k; i++) {
      if (k % i == 0) {
        good = false;
        break;
      }
    }
    if (good)
      PRIMES.insert(k);
  }
}

int main(int argc, char *argv[]) {
  init();
  int T;
  cin >> T;
  /*
   * 12 -> 2 * 2 * 3
   * 8 -> 2 * 2 * 2: {1, 2, 4, 8}
   * 15 -> 3 * 5: {1, 3, 5, 15}
   * 21 -> 3 * 7: {1, 3, 7, 21}
   * 猜想：奇数个prime相乘 -> strongly composite
   */
  while (T-- > 0) {
    int n;
    cin >> n;
    int good = 0, bad = 0, single = 0;
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      if (is_strongly_composite(ai, nullptr, nullptr)) {
        good += 1;
      } else if (PRIMES.find(ai) != PRIMES.end()) {
        single += 1;
      } else {
        bad += 1;
      }
    }
    cout << "ans: " << good << " " << bad << " " << single << endl;

    if (bad > single) {
      cout << 0 << endl;
      continue;
    }
    int extra = single - bad;
    int more = extra / 3;
    extra %= 3;
    if (extra == 1 && more == 0) {
      cout << 0 << endl;
      continue;
    } else {
      more -= 1;
    }
    cout << good + bad + more << endl;
  }
  return 0;

  // for (int i = 1; i < 100; i++) {
  //  int k = i;
  //  vector<int> primes, composites;
  //  if (is_strongly_composite(k, primes, composites)) {
  //    cout << i << "is strongly composite, factors are: " << endl;
  //    while (k > 1) {
  //      for (auto &v : PRIMES) {
  //        if (k % v == 0) {
  //          cout << v << " ";
  //          k /= v;
  //        }
  //      }
  //    }
  //    cout << endl;
  //    cout << "primes: ";
  //    for (auto &v : primes) {
  //      cout << v << " ";
  //    }
  //    cout << endl;
  //    cout << "composites: ";
  //    for (auto &v : composites) {
  //      cout << v << " ";
  //    }
  //    cout << endl;
  //  }
  //}
}

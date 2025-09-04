//https://www.spoj.com/problems/FACTCG2/
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const int limit = 1e7;

vector<int> get_primes() {
    int lim = sqrt(limit) + 1;
    vector<bool> is_prime(lim + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= lim; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= lim; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= lim; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> primes = get_primes();
    int n;
    while ((cin >> n)) {
        string ans; ans.reserve(100);
        ans += "1";
        for (int prime : primes) {
            while (n % prime == 0) {
                ans += " x " + to_string(prime);
                n /= prime;
            }
        }

        if (n > 1) ans += " x " + to_string(n);

        cout << ans << "\n";
    }

    return 0;
}
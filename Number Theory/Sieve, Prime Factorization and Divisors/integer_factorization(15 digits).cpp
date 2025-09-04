//https://www.spoj.com/problems/FACT0/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const long long limit = 1e15;

vector<int> get_primes() {

    int lim = sqrt(limit);
    vector<bool> is_prime(lim + 1, true);
    for (long long p = 2; p * p <= lim; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= lim; i += p) {
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
    long long n;
    while ((cin >> n)) {
        if (n == 0) break;
        string ans;
        ans.reserve(100);

        for (long long prime : primes) {
            if (prime * prime > n) {
                break;
            }


            int t = 0;
            while (n % prime == 0) {
                t++;
                n /= prime;
            }

            if (t > 0)  ans += to_string(prime) + "^" + to_string(t) + " ";
        }

        if (n > 1) ans += to_string(n) + "^1\n";
        else ans[ans.size() - 1] = '\n';

        cout << ans;
    }

    return 0;
}
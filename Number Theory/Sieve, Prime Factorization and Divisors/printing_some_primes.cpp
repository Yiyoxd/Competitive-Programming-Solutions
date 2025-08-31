//https://www.spoj.com/problems/TDPRIMES/

#include <iostream>
#include<vector>
using namespace std;

const int limit = 1e8;

vector<int> get_primes() {
    vector<bool> is_prime(limit, true);
    for (int p = 2; p * p < limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int> out;
    out.reserve(6e6);
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            out.push_back(i);
        }
    }

    return out;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);

    vector<int> primes = get_primes();
    for (int i = 0, n = primes.size(); i < n; i += 100) {
        cout << primes[i] << endl;
    }

    return 0;
}
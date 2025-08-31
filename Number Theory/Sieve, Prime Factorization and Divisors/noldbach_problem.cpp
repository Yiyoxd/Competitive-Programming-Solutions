//https://codeforces.com/problemset/problem/17/A
#include <iostream>
#include <vector>
using namespace std;

vector<int> get_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    for (int p = 2; p * p < limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

bool is_noldbach(int n, vector<int>& primes) {
    for (size_t i = 1; i < primes.size() && primes[i] + primes[i - 1] < n; i++) {
        if (primes[i] + primes[i - 1] == n - 1) {
            //cout << n << " " << primes[i] << " " << primes[i - 1] << endl;
            return true;
        }
    }

    return false;
}

int main() { 
    int n, k;
    cin >> n >> k;
    /*if (k <= 0) {
        cout << "YES" << endl;
        return 0;
    }*/
    vector<int> primes = get_primes(n);
    /*for (int prime  : primes) {
        cout << prime << " ";
    }*/
    for (int prime : primes) {
        if (is_noldbach(prime, primes) && --k <= 0) {
            //cout << i << endl;
            break;
        }
    }

    cout << (k > 0 ? "NO" : "YES") << endl;
}
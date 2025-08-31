//https://toph.co/p/n-th-prime

#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
using ulll = __uint128_t;

int small_primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int bases[3] = {2, 7, 61};

int mod_pow(ull base, int e, int mod) {
    base %= mod;
    ull ans = 1;
    while (e) {
        if (e & 1) ans = ans * base % mod;
        base = base * base % mod;
        e >>= 1;
    }

    return ans;
}

bool check_composite(int n, int a, int d, int r) {
    if (a % n == 0) {
        return false;
    }
    ull x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1ull) {
        return false;
    }

    for (int i = 1; i < r; i++) {
        x = x * x % n;
        if (x == n-1ull) {
            return false;
        }
    }

    return true;
}

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }

    for (int prime : small_primes) {
        if (n == prime) {
            return true;
        }
        if (n % prime == 0) {
            return false;
        }
    }

    int r = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    } 

    for (int base : bases) {
        if (check_composite(n, base, d, r)) {
            return false;
        }
    }

    return true;
}

vector<int> get_primes() {
    const int max_num = 7368787; //its the 500,000 th prime
    vector<bool> is_prime(max_num + 1, true);

    for (int p = 2; p * p < max_num; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int>primes(500000);
    for (int i = 2, j = 0; i <= max_num; i++) {
        if (is_prime[i]) {
            primes[j++] = i;
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;
    /*
        version 1 with Miller-Rabin Test
        acepted with 0.4s runtime
        if (n == 1) {
            cout << 2 << endl;
            return 0;
        }
        int primes_found = 1;
        int num = 3;
        while (primes_found < n) {
            if (is_prime(num)) {
                //cout << num << endl;
                primes_found++;
            }
            num += 2;
        }

        cout << num - 2 << endl;
    */

    //Version 2 with sieve of Erathostenes, 0.3s runtime
    vector<int> primes = get_primes();
    cout << primes[n - 1] << endl;

    return 0;
}
//https://cses.fi/problemset/task/1713
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int LIMIT = 1000000;
vector<bool> is_prime(LIMIT + 10, true);
vector<int>primes;
int divisors[LIMIT + 10];

void sieve() {
    //cout << "xd" << "\n";
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    primes.reserve(100000);
    for (int i = 2; i < LIMIT; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void fillDivisors() {
    divisors[0] = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (is_prime[i]) { 
            divisors[i] = 2;
            continue;
        }

        int n = i, divs = 1;
        for (int prime : primes) {
            if (((long long) prime) * prime > n) {
                break;
            }
            
            int exp = 0;
            while (n % prime == 0) {
                n /= prime;
                exp++;
            }
            
            divs *= (exp + 1);
        }

        if (n > 1) divs *= 2;

        divisors[i] = divs;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    sieve();
    fillDivisors();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        /*
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        if (is_prime[n]) {
            cout << 2 << endl;
            continue;
        }
        
        int t = 2;
        for (int prime : primes) {
            if (prime * prime >= n) {
                break;
            }
            
            if (n % prime == 0) {
                t += 2;
            }
        }
        */

        cout << divisors[n] << "\n";
    }
}
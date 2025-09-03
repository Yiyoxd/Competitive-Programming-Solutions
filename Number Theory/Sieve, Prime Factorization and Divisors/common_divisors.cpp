#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_set>

int limit = 1e6;

using namespace std;

pair<vector<bool>, vector<int>> get_primes() {
    vector<bool> is_prime(limit + 1, true);
    for (int p = 2; p * p < limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    /*
    
    for (int i = 0; i < 100; i++) {
        cout << primes[i] << " ";
    }

    cout << endl;

    //cout << "xd" << endl;
    */
    return {is_prime, primes};
}

vector<vector<int>> get_divisors() {
    pair<vector<bool>, vector<int>> primesPair = get_primes();
    vector<bool>& is_prime = primesPair.first;
    vector<int>& primes = primesPair.second;

    vector<vector<int>> divisors(limit + 1);
    //divisors[1].push_back(1);

    for (int i = 2; i <= limit; i++) {
        divisors[i].push_back(i);
        if (is_prime[i]) {
            //divisors[i].push_back(1);
            continue;
        }

        for (int prime : primes) {
            if (prime * prime == i) {
                //divisors[i].push_back(1);
                divisors[i].push_back(prime);
                break;
            }

            if (i % prime == 0) {
                int div = i / prime;
                for (int divisor : divisors[div]) {
                    divisors[i].push_back(divisor);
                    divisors[i].push_back(i / divisor);
                }
                //divisors[i].push_back(prime);
                break;
            }
        }
    }

    return divisors;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    

    int n;
    cin >> n;
    //int arr[n];
/*
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;        
        unordered_set<int> s;
        for (int prime : primes) {
            if (((long long)prime) * prime > x) {
                break;
            }
            
            while (x % prime == 0) {
                if (!s.count(x)) {
                    divisors[x]++;
                    s.insert(x);
                }
                if (!s.count(prime)) {
                    divisors[prime]++;
                    s.insert(prime);
                }
                if (!s.count(x / prime)) {
                    divisors[x / prime]++;
                    s.insert(x / prime);
                }

                x /= prime;
            }
        }
        
        if (!s.count(x)) {
            divisors[x]++;
        }
    }*/

    vector<vector<int>> divs = get_divisors();
    vector<int> divisors(limit + 1, 0);
    while (n--) {
        int x;
        cin >> x;
        for (int divisor : divs[x]) {
            divisors[divisor]++;
        }
    }


    int ans = 1;
    for (int i = limit; i > 1; i--) {
        if (divisors[i] > 1) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
//https://www.spoj.com/problems/PTRI2/
#include <bits/stdc++.h>
using namespace std;

const int limit = 1e8;

vector<pair<int, int>> get_primes() {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            } 
        }
    }

    vector<pair<int, int>> primes(limit + 1);
    //primes.reserve(1e6);

    for (int i = 1, row = 1, col = 1; i <= limit; i++) {
        if (is_prime[i]) {
            primes[i] = {row, col};
            if (++col > row) {
                row++;
                col = 1;
            }
        } else {
            primes[i] = {-1, -1};
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> primes = get_primes();
    //cout << "xd" << endl;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        pair<int, int>& p = primes[n];
        if (p.first == -1) {
            cout << "-1\n";
        } else {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}
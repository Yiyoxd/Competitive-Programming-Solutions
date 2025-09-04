//https://www.spoj.com/problems/VECTAR8/
#include <bits/stdc++.h>
using namespace std;

int lim = 1e6;

vector<bool> sieve() {
    vector<bool> is_prime(lim + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < lim; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < lim; i += p) {
                is_prime[i] = false;
            }
        }
    }

    return is_prime;
}

bool isSuperPrime(int n, vector<bool>& is_prime) {
    if (!is_prime[n]) return false;

    int copy = n, base = 1;
    while (copy >= 10) {
        if (copy % 10 == 0) return false;
        copy /= 10;
        base *= 10;
    }

    while (n >= 10) {
        //cout << n << endl;
        //if (n % 10 == 0) return true;
        if (!is_prime[n]) return false;
        int div = n / base;
        n -= base * div;
        base /= 10;
    }

    return is_prime[n];
}


int main() {
    vector<bool> is_prime = sieve();
    vector<int> prefix(lim + 1);
    //cout << "xd" << endl;
    prefix[0] = 0;

    for (int i = 1; i <= lim; i++) {
        prefix[i] = prefix[i - 1];
        if (isSuperPrime(i, is_prime)) prefix[i]++;
    }

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << prefix[n] << "\n";
    }
    
    return 0;
}
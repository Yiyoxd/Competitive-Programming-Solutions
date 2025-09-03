//https://codeforces.com/contest/776/problem/B

#include <bits/stdc++.h>
using namespace std;

vector<bool> get_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i+= p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            //cout << i;
        }
    }
    //cout << "\n";

    return is_prime;
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n1 1\n";
        return 0;
    }

    vector<bool> primes = get_primes(n + 3);
    string ansStr;
    ansStr.reserve(n * 6);

    for (int i = 1; i <= n; i++) {
        int ans = primes[i + 1] ? 1 : 2;
        ansStr += to_string(ans) + " ";
    }

    cout << min(n, 2) << "\n";
    ansStr[ansStr.size() - 1] = '\n';
    cout << ansStr;
    return 0;
}
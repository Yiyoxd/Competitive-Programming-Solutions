//https://judge.yosupo.jp/problem/primality_test

#include <iostream>
using namespace std;
using u64 = long long;
using u128 = __uint128_t;

int bases[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

u64 mod_mul(u128 a, u64 b, u64 mod) {
    return a * b % mod;
}

u64 mod_pow(u64 base, u64 e, u64 mod) {
    base %= mod;
    u64 ans = 1;
    while (e) {
        if (e & 1) ans = mod_mul(ans, base, mod);

        e >>= 1;
        base = mod_mul(base, base, mod);
    }

    return ans;
}

bool check_composite(u64 n, u64 a, u64 d, int r) {
    u64 x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }

    for (int i = 1; i < r; i++) {
        x = mod_mul(x, x, n);
        if (x == n - 1) {
            return false;
        }
    }

    return true;
}


bool is_prime(u64 n) {
    if (n < 2) {
        return false;
    }

    for (int base : bases) {
        if (base == n) {
            return true;
        }

        if (n % base == 0) {
            return false;
        }
    }

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : bases) {
        if (check_composite(n, a, d, r)) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        u64 n;
        cin >> n;
        if (is_prime(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
//https://www.spoj.com/problems/PON/
 
#include <iostream>
#include <cstdint>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
 
int bases[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
 
long long mod_mul(u128 a, long long b, long long mod) {
    return a * b % mod;
}
 
long long mod_pow(long long base, long long e, long long mod) {
    long long ans = 1;
    base %= mod;
 
    while (e) {
        if (e & 1) ans = mod_mul(base, ans, mod);
        base = mod_mul(base, base, mod);
        e >>= 1;
    }
 
    return ans;
}
 
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }
 
    for (int i = 1; i < s; i++) {
        x = mod_mul(x, x, n);
        if (x == n - 1) {
            return false;
        }
    }
 
    return true;
}
 
bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
 
    for (int prime : bases) {
        if (n == prime) return true;
        if (n % prime == 0) return false;
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
        long long n;
        cin >> n;
        if (is_prime(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
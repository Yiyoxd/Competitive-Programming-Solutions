//
// Created by yiyoa on 14/11/2025.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back()
#define F first
#define S second
#define sz(x) (int)(x).size()
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define forN(n, v) for (int i = 0; i < n; i++) cin >> v[i]
#define eraseU(v) v.erase(unique(v.begin(), v.end()), v.end())

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e18 + 10;
constexpr double EPS = 1e-9;
const double PI = acos(-1.0);
const vector<pii> DIR4 = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int modpow(int a, int e, int m) {
    int r = 1;
    while (e) {
        if (e & 1) {
            r = (r * a) % m;
        }
        a = (a * a) % m;
        e >>= 1;
    }

    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int P = 0, Q = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        sum -= v[i];
        P = (P + (v[i] * (sum % MOD)) % MOD) % MOD;
    }

    //cout << P << " " << Q << endl;

    int inv = modpow(Q % MOD, MOD - 2, MOD);
    cout << (P % MOD) * (inv % MOD) % MOD << "\n";
}

int32_t main() {
    IO
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
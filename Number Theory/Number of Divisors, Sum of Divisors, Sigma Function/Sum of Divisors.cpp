//
// Created by yiyoa on 15/11/2025.
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
const vector<pii > DIR4 = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<int>primos(int n) {
    int lim = sqrt(n) + 1;
    vector<bool> esprimo(lim + 1, true);
    for (int i = 2; i <= lim; i++) {
        if (esprimo[i]) {
            for (int j = i * i; j <= lim; j++) {
                esprimo[j] = false;
            }
        }
    }

    vector<int> out;
    for (int i = 2; i <= lim; i++) {
        if (esprimo[i]) {
            out.push_back(i);
        }
    }


    if (out.empty()) {
        out = {n};
    }

    return out;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p  = primos(n);
    vector<pii> pares;
    for (int primo : p) {
        pii p = {primo, 0};
        while (n % primo == 0) {
            p.second++;
            n /= primo;
        }


        if (p.second > 0) {
            pares.push_back(p);
        }
    }

    if (n > 1) {
        pares.push_back({n, 1});
    }

    int t = 1;
    for (auto[p, a] : pares) {
        int val = 1;
        int curr = 0;
        for (int i = 0; i <= a; i++) {
            curr += val;
            val *= p;
        }

        //cout << p << " " << a << " " << curr << endl;

        t = (t * (curr % MOD)) % MOD;
    }

    cout << t << "\n";
}

int32_t main() {
    //cout << "hola ejej " << endl;
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

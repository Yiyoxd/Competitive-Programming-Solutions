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

void set_prec(int n = 10) {cout << fixed << setprecision(n);}

double r(vector<long double>&dp, vector<vector<int>>& g, int node, int par) {
    if (g[node].size() == 1) {
        return 0;
    }

    if (dp[node] != 0) {
        return dp[node];
    }

    long double t = 0.0;
    for (int child : g[node]) {
        if (child != par) {
            t += r(dp, g, child, node);
        }
    }

    dp[node] = 1.0 + (t / (g[node].size() - 1));
    return dp[node];
}

void solve() {
    int n;
    cin >> n;
    vvi g(n + 1, vi());
    vector<long double> dp(n + 1, 0.0);
    g[1].push_back(0);

    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    set_prec(7);
    cout << r(dp, g, 1, 0);
}

//https://codeforces.com/problemset/problem/839/C
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

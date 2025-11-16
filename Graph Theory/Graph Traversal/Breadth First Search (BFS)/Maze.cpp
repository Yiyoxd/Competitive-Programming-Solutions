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
const vector<pii > DIR4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<pii > DIR8 = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};
void set_prec(int n = 10) { cout << fixed << setprecision(n); }

int n, m, k;

bool ok(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

void dfs(vector<string>&g, queue<pii>&q, int r, int c) {
    if (!ok(r, c) || g[r][c] != '.') {
        return;
    }

    q.push({r, c});
    g[r][c] = 'A';
    if (q.size() > k) {
        q.pop();
    }

    for (const auto[y, x] : DIR4) {
        dfs(g, q, r + y, c + x);
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<string>g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    queue<pii>q;
    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                dfs(g, q, i, j);
                break;
            }
        }
    }

    while (!q.empty()) {
        const auto[y, x] = q.front();
        q.pop();

        g[y][x] = 'X';
    }

    for (int i = 0; i < n && !flag; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                g[i][j] = '.';
            }
        }
    }

    for (string& s : g) {
        cout << s << "\n";
    }
}

//https://codeforces.com/contest/378/problem/C
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

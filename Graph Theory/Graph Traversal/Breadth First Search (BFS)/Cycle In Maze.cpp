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
const vector<pii > DIR4 = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const vector<char> MOVES = {'D', 'L', 'R', 'U'};
const vector<pii > DIR8 = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};
void set_prec(int n = 10) { cout << fixed << setprecision(n); }

string ans;
int n, m, k;

bool dfs(vector<string>& g, int r, int c, int k) {
    if (k == 0) {
        return g[r][c] == 'X';
    }

    //cout << r << " " << c << endl;
    //seen[r][c].insert(k);
    for (int i = 0; i < 4; i++) {
        int row = r + DIR4[i].first, col = c + DIR4[i].second;
        if (row < 0 || col < 0 || row >= n || col >= m || g[row][col] == '*') {
            continue;
        }

        ans.push_back(MOVES[i]);
        if (dfs(g, row, col, k - 1)) {
            return true;
        }

        ans.pop_back();
    }

    return false;
}

void solve() {
    cin >> n >> m >> k;
    vector<string>g(n);
    pii s;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                s = {i, j};
            }
        }
    }

    if (k%2 == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    //vector<vector<unordered_set<int>>> seen(n, vector<unordered_set<int>>(m, unordered_set<int>()));
    ans.reserve(k);
    //cout << "asas" << endl;
    if (dfs(g, s.first, s.second, k)) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

//
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

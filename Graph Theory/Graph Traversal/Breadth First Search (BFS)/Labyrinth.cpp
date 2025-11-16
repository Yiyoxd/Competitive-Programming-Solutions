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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> lab(n);
    pii start, end;

    for (int i = 0; i < n; i++) {
        cin >> lab[i];
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 'A') {
                start = {i, j};
            } else if (lab[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    queue<pii> q;
    q.push(end);
    bool found = false;

    vvi paths(n, vector<int>(m, -1));
    while (!q.empty() && !found) {
        const auto[r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            const auto[y, x] = DIR4[i];
            int row = r + y, col = c + x;
            if (row < 0 || col < 0 || row >= n || col >= m || lab[row][col] == '#') {
                continue;
            }


            //cout << row << " " << col << endl;

            paths[row][col] = i;
            q.push({row, col});
            if (lab[row][col] == 'A') {
                found = true;
                break;
            }
            lab[row][col] = '#';
        }
    }

    if (!found) {
        cout << "NO\n";
        return;
    }

    //vector<char> moves2 = {'U', 'D', 'L', 'R'};
    vector<char> moves = {'D', 'U', 'R', 'L'};
    string path;
    path.reserve(n * m);
    pii node = start;

    //cout << "xddd" << endl;
    while (node != end) {
        const auto[r, c] = node;
        int i = paths[r][c];
        const auto[y, x] = DIR4[i];
        path.push_back(moves[i]);
        node = {r - y, c - x};
    }

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path;
    cout << "\n";
}

//https://cses.fi/problemset/task/1193
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

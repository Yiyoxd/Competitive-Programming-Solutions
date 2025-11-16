#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

vi ans;

bool ok(vvi& g, vi& states, int node) {
    if (states[node] == 2) {
        return true;
    }

    if (states[node] == 1) {
        return false;
    }

    states[node] = 1;
    for (int nei : g[node]) {
        if (!ok(g, states, nei)) {
            return false;
        }
    }

    states[node] = 2;
    ans.push_back(node);
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vvi g(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    ans.reserve(n);
    vi states(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!ok(g, states, i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    reverse(ans.begin(), ans.end());
    string out;
    out.reserve(n * 7);
    for (int num : ans) {
        out += to_string(num) + ' ';
    }

    out[out.size() - 1] = '\n';
    cout << out;
}

//https://cses.fi/problemset/task/1679
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
//
// Created by yiyoa on 13/11/2025.
//

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

const int MOD = 1e9 + 7;
const int INF = 1e18 + 10;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const vector<pii> DIR4 = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};


constexpr int UNVISITED = 0, VISITING = 1, VISITED = 2;

bool ok(map<char, set<char>>& g, map<char, int>& seen, string& ans, char c) {
    if (seen[c] == VISITED) {
        return true;
    }

    if (seen[c] == VISITING) {
        return false;
    }

    seen[c] = VISITING;
    for (const char neigh : g[c]) {
        if (!ok(g, seen, ans, neigh)) {
            return false;
        }
    }

    ans += c;
    seen[c] = VISITED;
    return true;
}

void solve() {
    int n;
    cin >> n;

    map<char, set<char>>g;
    string ans;

    string prev;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool diff = false;
        int mn = min(s.size(), prev.size());
        for (int i = 0; i < mn; i++) {
            if (prev[i] != s[i]) {
                diff = true;
                g[prev[i]].insert(s[i]);
                break;
            }
        }

        if (!diff && prev.size() > s.size()) {
            cout << "Impossible\n";
            return;
        }

        prev = s;
    }

    map<char, int> s;
    for (char c = 'a'; c <= 'z'; c++) {
        if (!ok(g, s, ans, c)) {
            cout << "Impossible\n";
            return;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

//https://codeforces.com/problemset/problem/510/C
int32_t main() {
    IO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
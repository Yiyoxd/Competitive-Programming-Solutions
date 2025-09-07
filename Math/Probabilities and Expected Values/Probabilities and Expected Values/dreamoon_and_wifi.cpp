//https://codeforces.com/problemset/problem/476/B
#include <bits/stdc++.h>
using namespace std;

int needed = 0, total = 0;

void count (string t, int i, int curr) {
    if (i == t.size()) {
        if (needed == curr) total++;
        return;
    }

    if (t[i] == '+') {
        count(t, i + 1, curr + 1);
    } else if (t[i] == '-') {
        count(t, i + 1, curr - 1);
    } else {
        count(t, i + 1, curr + 1);
        count(t, i + 1, curr - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int ask = 0;
    for (int i = 0; i < n; i++) {
        needed += s[i] == '+' ? 1 : -1;
        if (t[i] == '?') ask++;
    }

    count(t, 0, 0);
    int totalWays = 1 << ask;
    cout << fixed << setprecision(10);
    cout << (long double) total / totalWays << endl;
}
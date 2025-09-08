//https://codeforces.com/problemset/problem/1461/C
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int needed = 0;
    for (int i = n; i > 0; i--) {
        if (arr[i] != i) {
            needed = i;
            break;
        }
    }

    long double P = 1;
    int maxR = 0;
    while (q--) {
        int ran;
        cin >> ran;

        long double p;
        cin >> p;
        
        if (ran >= needed) {
            P *= (1 - p);
        }
    }

    if (needed == 0) {
        cout << "1.000000\n";
    } else {
        cout <<  1.0 - P << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

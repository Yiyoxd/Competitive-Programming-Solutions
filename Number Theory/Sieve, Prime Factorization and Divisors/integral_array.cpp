//https://codeforces.com/contest/1649/problem/D
#include <bits/stdc++.h>
using namespace std;
vector<bool> vis(1000001, false);

void solve(const int n, int m) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!vis[x]) {
            arr.push_back(x);
            vis[x] = true;
        }
    }

    string ans = "YES";
    sort(arr.begin(), arr.end());
    //cout << arr[0] << "   " << arr[1] << endl;
    for (int i = arr.size() - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (!vis[arr[i] / arr[j]]) {
                ans = "NO";
                i = j = 0;
            }
        }
    }
    
    
    for (int num : arr) {
        vis[num] = false;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        solve(n, m);
    }

    return 0;
}
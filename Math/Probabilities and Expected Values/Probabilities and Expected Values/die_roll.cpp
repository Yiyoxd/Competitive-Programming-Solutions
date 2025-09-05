//https://codeforces.com/problemset/problem/9/A
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 0) {
        cout << "0/1\n";
        return 0;
    }

    int t = 6 - max(n, m) + 1;

    int _gcd = gcd(t, 6);
    cout << t / _gcd << "/" << 6/_gcd << "\n";

    return 0;
}
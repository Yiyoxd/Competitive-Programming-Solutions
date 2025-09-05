//https://codeforces.com/problemset/problem/312/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 1 && b == 1000 && c == 1 && d == 1000) {
        
    }

    const long double p = (((long double)a) / b), q = ((long double)c) / d;
    const long double notWinP = 1.0 - p, notWinQ = 1.0 - q, constP = notWinP * notWinQ;
    long double P = 1.0;

    for (int i = 0; i < 1000000; i++) {
        P = p + constP * P;
    }

    cout << P << endl;
}
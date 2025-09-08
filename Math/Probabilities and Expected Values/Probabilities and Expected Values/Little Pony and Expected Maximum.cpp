//https://codeforces.com/problemset/problem/453/A
#include <bits/stdc++.h>
using namespace std;

//just to test
int total = 0;

void gen(int n, int lim, int rem, string s, int maxV, vector<int>&c) {
    if (rem == 0) {
        c[maxV]++;
        cout << s + "  " << maxV << endl;
        total += maxV;
        return;
    }

    while (n <= lim) {
        gen(1, lim, rem - 1, s + to_string(n - 1), max(maxV, n++), c);
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> c(n + 1, 0);
    gen(1, n, m, "", 0, c);
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
   
    long long total = 1, sumExp = 1;
    for (int i = 1; i < n; i++) {
        total += n * i;
        sumExp += total * (i + 1);
    }

    cout << sumExp / pow(n, m);

    //cout << endl << total / pow(n, m) << endl;
}
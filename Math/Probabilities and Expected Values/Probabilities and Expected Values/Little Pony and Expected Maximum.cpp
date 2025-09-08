//https://codeforces.com/problemset/problem/453/A
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

/*just to test
int total = 0;

void gen(int n, int lim, int rem, int maxV, vector<int>&c) {
    if (rem == 0) {
        c[maxV]++;
        //cout << s + "  " << maxV << endl;
        total += maxV;
        return;
    } 

    while (n <= lim) {
        gen(1, lim, rem - 1, max(maxV, n++), c);
    }
}*/



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    for (int i = 0; i < 10; i++) {
        int n, m; //cin >> n >> m;
        n = 6; m = i + 1;
        vector<int> c(n + 1, 0);
        gen(1, n, m, 0, c);
        long long ttt = 0;
        for (int i = 1; i <= n; i++) {
            cout << c[i] << " ";
            ttt += (c[i] * i);
        }
        cout << endl;
    
        long long total = 1, sumExp = 1;
        //cout << "1 ";
        for (int i = 1; i < n; i++) {
            total += n * i;
            //cout << total << " ";
            sumExp += total * (i + 1);
        }
        
        //cout << "\n" << total << endl;

        cout << ttt / pow(n, m) << endl;
    }*/

    //cout << endl << total / pow(n, m) << endl;

    long double m, n;
    cin >> m >> n;

    long double exp = 0;
    for (int k = 1; k <= m; k++) {
        exp += (pow(k / m, n) - pow((k - 1) / m, n)) * k;
    }

    //The expected value = from k = 1 to m : (Sum(P(1 to k appears in n throws) - P(1 to k-1 appers in n throws))) * k
    cout << exp << endl;
    return 0;
}
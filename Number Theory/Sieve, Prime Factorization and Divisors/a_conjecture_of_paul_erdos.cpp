//https://www.spoj.com/problems/HS08PAUL/
#include <bits/stdc++.h>
using namespace std;

const int maxSqrt = 3163;
const int maxSqrt4 = 56; //57 ^ 4 > maxN
const int maxN = 10000000;

vector<bool> get_primes() {
    vector<bool> is_prime(maxN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= maxN; p++) {
        if (is_prime[p]) {
            //cout << p << endl;
            for (int i = p * p; i <= maxN; i += p) {
                is_prime[i] = false;
            }
        }
    }

    return is_prime;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<bool> sqrts(maxSqrt * maxSqrt + 1, false);
    for (int i = 1; i <= maxSqrt; i++) {
        sqrts[i * i] = true;
    }

    vector<int> sqrts4(maxSqrt4 + 3);
    for (int i = 0; i <= maxSqrt4 + 1; i++) {
        sqrts4[i] = i * i * i * i;
    }
    
    vector<int> prefix(maxN);
    vector<bool> is_prime = get_primes();
    prefix[0] = 0;
    for (int i = 1; i < maxN; i++) {
        prefix[i] = prefix[i - 1];
        if (!is_prime[i]) {
            continue;
        }

        //cout << i << endl;
        for (int j = 1; sqrts4[j] < i; j++) {
            if (sqrts[i - sqrts4[j]]) {
                prefix[i]++;
                break;
            }
        }
    }

    //cout << "xd" << endl;

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        cout << prefix[num] << "\n";
    }

    for (int i = 0; i < 1000; i++) {
        //cout << i << "  " << prefix[i] << endl;
    }

    return 0;
}
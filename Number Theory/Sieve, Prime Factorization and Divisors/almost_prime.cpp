//https://codeforces.com/problemset/problem/26/A 

#include<iostream>
#include<vector>
using namespace std;

vector<int> get_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p < n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    vector<int> out;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            out.push_back(i);
        }
    }

    return out;
}

int main() {
    int n, total = 0;
    cin >> n;
    vector<int> primes = get_primes(n);
    for (int i = 2; i <= n; i++) {
        int currNum = i;
        int count = 0;
        for (int num : primes) {
            if (currNum % num == 0 && ++count > 2) {
                break;
            }

            while (currNum % num == 0) {
                currNum /= num;
            }
        }
        
        if (count == 2) {
            total++;
        }
    }

    cout << total << endl;
    return 0;
}
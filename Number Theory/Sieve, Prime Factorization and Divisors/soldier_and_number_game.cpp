//https://codeforces.com/contest/546/problem/D

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

const int LIMIT = 5000005;
vector<bool> is_prime(LIMIT + 1, true);
int soldiers[LIMIT + 1];
int amountOfSoldiers[LIMIT + 1];
vector<int> primes;

void calculate_primes(int n = LIMIT) {
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (is_prime[p]) {
            //primes.push_back(i);
            for (int i = p * p; i < n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    //cout << primes.size() << endl;
}

void calculateSoldiers() {
    soldiers[0] = soldiers[1] = 0;

    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime[i]) {
            soldiers[i] = 1;
            continue;
        }

        int num = i, cont = 0;
        for (int prime : primes) {
            if (prime * prime > num) break;

            if (i % prime == 0) {
                //cout << i << "   " << prime << endl;
                cont = soldiers[i / prime];
                //num = 1;
                break;
            }
        }

        if (num > 1) cont++;

        soldiers[i] = cont;
    }

    //cout << "xd" << endl;

    amountOfSoldiers[0] = 0;
    for (int i = 1; i <= LIMIT; i++) {
        amountOfSoldiers[i] = soldiers[i] + amountOfSoldiers[i - 1];
        //cout << i << " " << amountOfSoldiers[i] << endl;;
    }
    //cout << "xd" << amountOfSoldiers[LIMIT] << endl;
}

void solve(int a, int b) {
    //cout << amountOfSoldiers[a];
    cout << amountOfSoldiers[a] - amountOfSoldiers[b] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    calculate_primes();
    calculateSoldiers();

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        //long long curr = 1;
        //int t = 0, n = 1;
        /*
            
        for (int i = 2; i <= a; i++) {
            n *= i;
            for (int prime: primes) {
                if (prime * prime > n) {
                    break;
                }

                while (n % prime == 0) {
                    t++;
                    n /= prime;
                }
            }

            if (n > 1)  {
                t++;
                n = 1;
            }
        }
        
        */

        

        //cout << "Normal: " << t << ", precalculo: " << amountOfSoldiers[a]; 
        /*
            for (int i = b + 1; i <= a; i++) {
                curr *= i;
                for (int prime : primes) {
                    if (prime > curr) {
                        break;
                    }

                    
                    while (curr % prime == 0) {
                        curr /= prime;
                        cout << curr << "     " << prime << endl;
                    }
                }
            }
        */
       
        
        solve(a, b);
    }

    return 0;
}
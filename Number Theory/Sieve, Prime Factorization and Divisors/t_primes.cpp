//https://codeforces.com/problemset/problem/230/B

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> get_primes(int lim) {
    vector<bool> is_prime(lim + 1, true);
    for (int i = 2; i * i <= lim; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= lim; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> out;
    for (int i = 2; i <= lim; i++) {
        if (is_prime[i]) {
            out.push_back(i);
        }
    }

    return out;
}

bool binarySearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return true;
        }

        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> primes = get_primes(1000001);
    //for (int i = 0; i < 10; i++) {
    //    cout << primes[i] << " ";
    //}
    //cout << endl;
    int n;
    cin >>n;
    while (n--) {
        long long curr;
        cin >> curr;
        long long raiz = sqrt(curr);
        if (raiz > 1 && raiz * raiz == curr && binarySearch(primes, raiz)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
//https://leetcode.com/problems/four-divisors/

class Solution {
#include <vector>
public:
    pair<vector<bool>, vector<int>> get_primes(int n = 1e5) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }

        vector<int> output = {2};
        for (int i = 3; i <= n; i += 2) {
            if (is_prime[i]) {
                output.push_back(i);
            }
        }

        return {is_prime, output};
    }

    int fourDivisors(int num, vector<int>& primes, vector<bool>& is_prime) {
        for (int prime : primes) {
            if (prime * prime > num) {
                return 0;
            }

            if (num % prime == 0) {
                if (prime * prime == num) {
                    return 0;
                }

                //cout << num << "   " << prime << endl;
                if (is_prime[num / prime] || (prime * prime * prime == num)) {
                    return 1 + num + prime + num / prime;
                }
                
                return 0;
            }
        }

        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        auto p = get_primes();
        vector<bool>& is_prime = p.first;
        vector<int>& primes = p.second;
        int total = 0;
        for (int num : nums) {
            total += fourDivisors(num, primes, is_prime);
        }

        return total;
    }
};
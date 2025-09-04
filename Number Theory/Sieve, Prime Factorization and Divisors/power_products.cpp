// https://codeforces.com/contest/1225/problem/D
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <string>
using namespace std;
const long long LIMIT = 1e5;
const long long lim = 1e10;
// using __uint128_t = unsigned __int128;

int search(vector<long long> &pwr, long long target)
{
    int l = 0, r = pwr.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (pwr[mid] == target)
        {
            return mid;
        }

        if (pwr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return l;
}

long long powXD(long long base, int exp)
{
    long long ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            if (ans > lim / base)
                return lim + 1;
            ans *= base;
        }
        exp >>= 1;
        if (exp)
        {
            if (base > lim / base)
                return lim + 1;
            base *= base;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    /*
        if (k == 1) {
            cin.ignore();
            string s;
            getline(cin, s);
            cout << n * (n - 1ll) / 2 << endl;
            return 0;
        }
    */

    vector<long long> powers;
    unordered_set<long long> is_perfect;
    int maxSqrt = sqrt(LIMIT);
    for (int i = 1; i <= LIMIT; i++) {

        // cout << p << endl;
        long long p = powXD(i, k);
        if (p > lim)
            break;

        long long pwr = (long long)(p);
        powers.push_back(pwr);
        is_perfect.insert(pwr);
    }

    // cout << powers.size() << " " << powers[2152] << " " << powers[2153] << endl;
    int maxIdx = powers.size() - 1, perfects = 0;
    vector<int> count(LIMIT + 1, 0);
    vector<int> countMul(maxSqrt + 1, 0);

    long long total = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (k == 2) {
            // count mantiene ocurrencias exactas de valores anteriores (1..LIMIT)
            // total ya lo tienes declarado afuera
            // dentro del for que lee cada 'num':
            // int num; cin >> num;

            // 1) Quitar cuadrados perfectos de 'num' para obtener su parte square-free
            int x = num;
            for (int d = 2; 1LL * d * d <= x; ++d) {
                long long sq = 1LL * d * d;
                while (x % sq == 0)
                    x /= sq; // divide mientras haya d^2
            }
            int sf = x; // square-free de num

            // 2) Sumar todos los anteriores que sean sf * (y*y) <= LIMIT
            for (long long y = 1;; ++y) {
                long long cand = 1LL * sf * y * y;
                if (cand > LIMIT)
                    break;
                total += count[(int)cand];
            }

            // 3) Registrar el 'num' actual
            if (num <= LIMIT)
                count[num]++;

            continue; // saltar al siguiente número (solo para k==2)
        }

        int l = search(powers, num);
        int r = maxIdx; // min(search(powers, lim / num) + 50, maxIdx);

        // cout << l << "   " << r << endl;
        // cout << powers[l] << " " << powers[r] << endl;

        // r = maxIdx;
        while (l <= r) {
            long long curr = powers[l++];
            if (curr / num > LIMIT)
                break;
            if (curr % num == 0)
                total += count[curr / num];
        }

        count[num]++;
    }

    cout << total << "\n";
    return 0;
}
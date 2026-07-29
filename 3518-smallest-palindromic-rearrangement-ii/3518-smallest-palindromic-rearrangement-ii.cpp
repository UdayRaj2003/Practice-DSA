#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long LIM = 1000001;

    long long combCap(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;

            long long g = gcd(a, b);
            a /= g;
            b /= g;

            g = gcd(res, b);
            res /= g;
            b /= g;

            if (res > cap / a)
                return cap;

            res *= a;
            res /= b;

            if (res >= cap)
                return cap;
        }

        return res;
    }

    long long countWays(vector<int> &freq, int total, long long cap) {
        long long ans = 1;
        int rem = total;

        for (int i = 0; i < 26; i++) {
            if (!freq[i]) continue;

            long long c = combCap(rem, freq[i], cap);

            if (ans >= cap || c >= cap)
                ans = cap;
            else {
                if (ans > cap / c)
                    ans = cap;
                else
                    ans *= c;
            }

            if (ans >= cap)
                return cap;

            rem -= freq[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
            freq[i] /= 2;
        }

        int half = s.size() / 2;

        if (countWays(freq, half, LIM) < k)
            return "";

        string left;

        for (int pos = 0; pos < half; pos++) {

            for (int c = 0; c < 26; c++) {

                if (freq[c] == 0)
                    continue;

                freq[c]--;

                long long cnt = countWays(freq, half - pos - 1, LIM);

                if (cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= cnt;
                freq[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
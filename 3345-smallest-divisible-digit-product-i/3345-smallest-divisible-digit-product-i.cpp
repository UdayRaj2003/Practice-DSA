class Solution {
public:
    int f(int n) {
        int m = 1;
        while (n) {
            m *= n % 10;
            n /= 10;
        }
        return m;
    }
    int smallestNumber(int n, int t) {
        if (n % 10 == 0) {
            return n;
        }
        int mul = f(n);
        int d = 1;
        while (n % 10) {
            if (mul % t == 0) {
                return n;
            }
            d = n % 10;
            mul = mul / d;
            mul *= d + 1;
            n += 1;
        }
        return n;
    }
};
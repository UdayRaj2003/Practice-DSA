class Solution {
public:
    int minimumPushes(string word) {
        int taps = 0, i = 1;
        int len = word.length();
        while (len > 0) {
            if (len > 8) {
                taps += i * 8;
            } else {
                taps += i * len;
            }
            i++;
            len -= 8;
        }
        return taps;
    }
};
class Compare {
public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    int minimumPushes(string word) {

        map<char, int> mp;

        for (char ch : word)
            mp[ch]++;

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), Compare());

        int i = 1, sum = 0, count = 1;

        for (auto &row : freq) {

            sum += count * row.second;

            cout << "sum: " << sum
                 << " count: " << count
                 << " char: " << row.first
                 << " freq: " << row.second << endl;

            if (i % 8 == 0)
                count++;

            i++;
        }

        return sum;
    }
};
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (auto &[x, f] : freq) {
                if (f == 1)
                    ans = max(ans, x);
            }

            return ans;
        }

        // Case 2: k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int first = nums[0];
        int last = nums[n - 1];

        int cf = 0, cl = 0;

        for (int x : nums) {
            if (x == first) cf++;
            if (x == last) cl++;
        }

        bool firstUnique = (cf == 1);
        bool lastUnique = (cl == 1);

        if (firstUnique && lastUnique)
            return max(first, last);

        if (firstUnique)
            return first;

        if (lastUnique)
            return last;

        return -1;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int all = 0;
        for (int i = 0; i < nums.size(); i++) {
            all ^= nums[i];
        }
        if (all != 0) {
            return nums.size();
        }
        int len = nums.size();
        int i = 0, j = len - 1;

        while (i < len && !all) {
            if(nums[i] != 0){
                return j;
            } else {
                i++;
            } 
        }
        return 0;
    }
};
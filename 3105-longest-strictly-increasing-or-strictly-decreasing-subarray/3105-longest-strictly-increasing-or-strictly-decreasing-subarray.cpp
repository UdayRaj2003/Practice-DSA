class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int c = 1,d=1;
        if (nums.size() == 1) {
            return 1;
        }
        int ans =1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                c++;
                d=1;
            }else if(nums[i]<nums[i-1]){
                d++;
                c=1;
            }else{
                c=1;d=1;
            }
            ans = max({d,ans,c});

        }
        return ans;
    }
};
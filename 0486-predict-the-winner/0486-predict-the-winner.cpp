class Solution {
public:
    bool f(int s, int e, bool p, int sum1, int sum2, vector<int>& nums) {
        if (s > e) {
            if (sum1 >= sum2) {
                cout<<sum1<<"  "<<sum2<<endl;
                return true;
            }
            else{
                return false;
            }
        }
        if (p) {
            return (f(s + 1, e, !p, sum1 + nums[s], sum2, nums) ||
                    f(s, e - 1, !p, sum1 + nums[e], sum2, nums));
        } else {
            return (f(s + 1, e, !p, sum1, sum2 + nums[s], nums) &&
                    f(s, e - 1, !p, sum1, sum2 + nums[e], nums));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int j = nums.size() - 1; 
        return f(0, j, 1, 0, 0 , nums) ;
    
    }
};
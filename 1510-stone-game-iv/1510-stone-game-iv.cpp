class Solution {
public:
    bool f(vector<vector<int>>& dp, int n, bool chan) {
        if (n == 0)
            return false;

        if (dp[n][chan] != -1) {
            return dp[n][chan];
        } 

        for (int i = 1; i <= sqrt(n); i++) {
              if (!f(dp, n - i * i, !chan)) {
                return dp[n][chan] = true;
            }
        }
        return dp[n][chan] =false;
    }

    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
 
        
        return f(dp, n, 1);
    }
};
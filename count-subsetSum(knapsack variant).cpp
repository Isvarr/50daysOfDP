class Solution {
public:
    int countSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= k; sum++) {
                int no = dp[i-1][sum];
                int yes = 0;
                if (nums[i-1] <= sum) {
                    yes = dp[i-1][sum-nums[i-1]];
                }
                dp[i][sum] = yes+no;
            }
        }
        return dp[n][k];
    }
};

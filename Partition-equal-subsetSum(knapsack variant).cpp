class Solution {
public:
    bool subsetsum(vector<int>&nums, int x){
        int n = nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(x+1,false));
        for (int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for (int i=1;i<=x;i++){
            dp[0][i]=false;
        }
        for (int i =1;i<=n;i++){
            for (int j=1;j<=x;j++){
                bool no = dp[i-1][j];
                bool yes = false;
                if(nums[i-1]<=j){
                    yes = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = yes || no;
            }
        }
        return dp[n][x];
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for (int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        int target = s/2;
        if (s%2==1){
            return false;
        }else{
            return subsetsum(nums,target);
        }
    }
};

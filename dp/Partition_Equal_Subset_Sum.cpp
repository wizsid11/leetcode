class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int s=sum/2;
        int n = nums.size();
        bool dp[n+1][s+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=s; j++){
                if(j==0)dp[i][j]=true;
                else if(j!=0 && i==0)dp[i][j]=false;
                else if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())return 0;
        else if(nums.size()==1)return nums[0];
        else if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>dp(nums.size()-1);
        dp[0]=nums[1];
        dp[1]=max(nums[1],nums[2]);
        for(int i=3; i<nums.size(); i++){
            dp[i-1] = max(nums[i]+dp[i-3], dp[i-2]);
        }
        vector<int>dr(nums.size()-1);
        dr[0]=nums[0];
        dr[1]=max(nums[0],nums[1]);
        for(int i=2; i<nums.size()-1; i++){
            dr[i] = max(nums[i]+dr[i-2], dr[i-1]);
        }
        
        return max(dp[nums.size()-2], dr[nums.size()-2]);
    }
};
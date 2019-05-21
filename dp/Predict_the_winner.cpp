class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;
        int dp[n][n];
        for (int gap = 0; gap < n; ++gap) { 
            for (int i = 0, j = gap; j < n; ++i, ++j) { 
                int x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
                int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
                int z = (i <= (j - 2)) ? dp[i][j - 2] : 0; 

                dp[i][j] = max(nums[i] + min(x, y), nums[j] + min(y, z)); 
            }
        }
        if(dp[0][n-1]>=min(dp[1][n-1], dp[0][n-2]))return true;
        else return false; 
    }
};
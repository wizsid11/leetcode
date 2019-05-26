class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=grid[i][j];
            }
        }
        dp[0][0]=grid[0][0];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)continue;
                else if(i==0 && j!=0)dp[i][j] += dp[i][j-1];
                else if(i!=0 && j==0)dp[i][j] += dp[i-1][j];
                else dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
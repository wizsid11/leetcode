class Solution {
public:
    vector<int>calculate(string str){
        vector<int>cal(2,0);
        for(int i=0; i<str.length(); i++){
            if(str[i]=='0')cal[0]++;
            else cal[1]++;
        }
        return cal;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        int dp[l+1][m+1][n+1];
        vector<int>nums;
        for(int i=0; i<=l; i++){
            if(i>0){
                nums = calculate(strs[i-1]);
            }
            for(int j=0; j<m+1; j++){
                for(int k=0; k<n+1; k++){
                    if(i==0)dp[i][j][k]=0;
                    else if(j>=nums[0] && k>=nums[1])
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-nums[0]][k-nums[1]]+1);
                    else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        return dp[l][m][n];
        
    }
};
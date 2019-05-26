class Solution {
public:
    int knightDialer(int N) {
        constexpr int kmod = 1e9 + 7;
        int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        vector<vector<int>>dp(4, vector<int>(3,1));
        dp[3][0] = dp[3][2] = 0;
        for(int k=1; k<N; k++){
            vector<vector<int>>temp(4, vector<int>(3));
            for(int i=0; i<4; i++){
                for(int j=0; j<3; j++){
                    if(i==3 && j!=1)continue;
                    for(int d=0; d<8; d++){
                        int tx = j+dirs[d][0];
                        int ty = i+dirs[d][1];
                        if (tx < 0 || ty < 0 || tx >= 3 || ty >= 4) continue;
                        temp[i][j] = (temp[i][j]+dp[ty][tx])%kmod;
                    }
                }
            }
            dp.swap(temp);
        }
        int ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                ans=(ans+dp[i][j])%kmod;
            }
        }
        return ans;
    }
};